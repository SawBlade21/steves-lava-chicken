#include <Geode/Geode.hpp>
#include <Geode/modify/Menulayer.hpp>

using namespace geode::prelude;


class $modify(Steve, MenuLayer) {
    void onChicken(CCObject*) {
		FMODAudioEngine::sharedEngine()->stopAllMusic(true);
		FMODAudioEngine::sharedEngine()->playMusic((Mod::get()->getSettingValue<bool>("remix")) ? "steves_lava_chicken_remix.mp3"_spr : "steves_lava_chicken.mp3"_spr, true, 0, 0);
    }

    bool init() {
        if (!MenuLayer::init()) return false;

        auto steveButton = CCMenuItemSpriteExtra::create(
            CCSprite::create("steve_button.png"_spr),
            this,
            menu_selector(Steve::onChicken)
        );

		auto menu = this->getChildByID("bottom-menu");
        menu->addChild(steveButton);
        
        steveButton->setPosition({175, 0});
		steveButton->setID("steve-button"_spr);
		menu->updateLayout();

		return true;

    }
};