include $(TOPDIR)/rules.mk

PKG_NAME:=tuya-SDK-libs
PKG_RELEASE:=1
PKG_VERSION:=1.0.0
PKG_SOURCE_PROTO:=git
PKG_SOURCE_URL:=https://github.com/tuya/tuya-iot-core-sdk
PKG_SOURCE_VERSION:=0208badefb2003d30e70b5b875395e3187c850d9

include $(INCLUDE_DIR)/package.mk

define Package/tuya-SDK-libs
	CATEGORY:=Libraries
	TITLE:=tuya-SDK-libs
endef

define Package/tuya-SDK-libs/description
	This is a package that contains libraries necesary to comunicate with tuya iot cloud
endef

define Build/InstallDev
	$(INSTALL_DIR) $(1)/usr/lib $(1)/usr/include

	$(INSTALL_BIN) $(PKG_BUILD_DIR)/build/lib/liblink_core.so $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/build/lib/libmiddleware_implementation.so $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/build/lib/libplatform_port.so $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/build/lib/libutils_modules.so $(1)/usr/lib

	$(INSTALL_DATA) $(PKG_BUILD_DIR)/include/tuyalink_core.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/include/tuya_endpoint.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/include/tuya_config_defaults.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/include/cipher_wrapper.h $(1)/usr/include/

	$(INSTALL_DATA) $(PKG_BUILD_DIR)/interface/http_client_interface.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/interface/mqtt_client_interface.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/interface/network_interface.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/interface/storage_interface.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/interface/system_interface.h $(1)/usr/include/

	$(INSTALL_DATA) $(PKG_BUILD_DIR)/utils/tuya_log.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/utils/tuya_error_code.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/utils/tuya_cloud_types.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/utils/MultiTimer.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/utils/log.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/utils/base64.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/utils/cJSON.h $(1)/usr/include/

	$(INSTALL_DATA) $(PKG_BUILD_DIR)/middleware/transport_interface.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/middleware/core_mqtt_config.h $(1)/usr/include/
	$(INSTALL_DATA) $(PKG_BUILD_DIR)/middleware/core_http_config.h $(1)/usr/include/
	
endef


define Package/tuya-SDK-libs/install
	$(INSTALL_DIR) $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/build/lib/liblink_core.so $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/build/lib/libmiddleware_implementation.so $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/build/lib/libplatform_port.so $(1)/usr/lib
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/build/lib/libutils_modules.so $(1)/usr/lib
endef

$(eval $(call BuildPackage,tuya-SDK-libs))