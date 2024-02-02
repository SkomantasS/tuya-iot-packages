include $(TOPDIR)/rules.mk

PKG_NAME:=tuya_switch_comm
PKG_RELEASE:=1
PKG_VERSION:=1.0.0

include $(INCLUDE_DIR)/package.mk

define Package/tuya_switch_comm
	CATEGORY:=Tuya
	TITLE:=tuya_switch_comm
	DEPENDS:=+tuya-SDK-libs +libubus +libubox
endef
#  +libblobmsg-json
#	DEPENDS:=+liblink_core +libmiddleware_implementation +libplatform_port +libutils_modules +libargp

#	DEPENDS:=+liblink_core
#	DEPENDS:=+libmiddleware_implementation
#	DEPENDS:=+libplatform_port
#	DEPENDS:=+libutils_modules
#	DEPENDS:=+libargp
#	DEPENDS:=+USE_UCLIBC:argp-standalone
	
define Package/tuya_switch_comm/description
	This is a package that communicates with tuya cloud
endef

define Package/tuya_switch_comm/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/tuya_switch_comm $(1)/usr/bin

endef

$(eval $(call BuildPackage,tuya_switch_comm))
