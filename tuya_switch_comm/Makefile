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
	
define Package/tuya_switch_comm/description
	This is a package that communicates with tuya cloud
endef

define Package/tuya_switch_comm/install
	$(INSTALL_DIR) $(1)/usr/bin
	$(INSTALL_DIR) $(1)/etc/config
	$(INSTALL_DIR) $(1)/etc/init.d
	$(INSTALL_BIN) $(PKG_BUILD_DIR)/tuya_switch_comm $(1)/usr/bin
	$(INSTALL_BIN) ./files/tuya_switch.init $(1)/etc/init.d/tuya_switch
	$(INSTALL_CONF) ./files/tuya_switch.config $(1)/etc/config/tuya_switch
endef

$(eval $(call BuildPackage,tuya_switch_comm))
