#include <libubox/blobmsg_json.h>
#include <libubus.h>
#include "ubus_functions.h"

static const struct blobmsg_policy memory_policy[__MEMORY_MAX] = {
	[TOTAL_MEMORY]	  = { .name = "total", .type = BLOBMSG_TYPE_INT64 },
	[FREE_MEMORY]	  = { .name = "free", .type = BLOBMSG_TYPE_INT64 },
	[SHARED_MEMORY]	  = { .name = "shared", .type = BLOBMSG_TYPE_INT64 },
	[BUFFERED_MEMORY] = { .name = "buffered", .type = BLOBMSG_TYPE_INT64 },
};

static const struct blobmsg_policy info_policy[__INFO_MAX] = {
	[MEMORY_DATA] = { .name = "memory", .type = BLOBMSG_TYPE_TABLE },
};

void board_cb(struct ubus_request *req, int type, struct blob_attr *msg)
{
	struct MemData *memoryData = (struct MemData *)req->priv;
	struct blob_attr *tb[__INFO_MAX];
	struct blob_attr *memory[__MEMORY_MAX];

	blobmsg_parse(info_policy, __INFO_MAX, tb, blob_data(msg), blob_len(msg));

	if (!tb[MEMORY_DATA]) {
		fprintf(stderr, "No memory data received\n");
		// rc = -1;
		return;
	}

	blobmsg_parse(memory_policy, __MEMORY_MAX, memory, blobmsg_data(tb[MEMORY_DATA]),
		      blobmsg_data_len(tb[MEMORY_DATA]));

	memoryData->total    = blobmsg_get_u64(memory[TOTAL_MEMORY]);
	memoryData->free     = blobmsg_get_u64(memory[FREE_MEMORY]);
	memoryData->shared   = blobmsg_get_u64(memory[SHARED_MEMORY]);
	memoryData->buffered = blobmsg_get_u64(memory[BUFFERED_MEMORY]);
}