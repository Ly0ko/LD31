#include <hxcpp.h>

#ifndef INCLUDED_Mob
#include <Mob.h>
#endif
#ifndef INCLUDED_PlayState
#include <PlayState.h>
#endif
#ifndef INCLUDED_Player
#include <Player.h>
#endif
#ifndef INCLUDED_Reg
#include <Reg.h>
#endif
#ifndef INCLUDED_flixel_FlxBasic
#include <flixel/FlxBasic.h>
#endif
#ifndef INCLUDED_flixel_FlxCamera
#include <flixel/FlxCamera.h>
#endif
#ifndef INCLUDED_flixel_FlxG
#include <flixel/FlxG.h>
#endif
#ifndef INCLUDED_flixel_FlxObject
#include <flixel/FlxObject.h>
#endif
#ifndef INCLUDED_flixel_FlxSprite
#include <flixel/FlxSprite.h>
#endif
#ifndef INCLUDED_flixel_FlxState
#include <flixel/FlxState.h>
#endif
#ifndef INCLUDED_flixel_group_FlxGroup
#include <flixel/group/FlxGroup.h>
#endif
#ifndef INCLUDED_flixel_group_FlxTypedGroup
#include <flixel/group/FlxTypedGroup.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxDestroyable
#include <flixel/interfaces/IFlxDestroyable.h>
#endif
#ifndef INCLUDED_flixel_interfaces_IFlxPooled
#include <flixel/interfaces/IFlxPooled.h>
#endif
#ifndef INCLUDED_flixel_text_FlxText
#include <flixel/text/FlxText.h>
#endif
#ifndef INCLUDED_flixel_tile_FlxTilemap
#include <flixel/tile/FlxTilemap.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif
#ifndef INCLUDED_openfl__v2_Assets
#include <openfl/_v2/Assets.h>
#endif

Void PlayState_obj::__construct(Dynamic MaxSize)
{
HX_STACK_FRAME("PlayState","new",0xf8bf96cf,"PlayState.new","PlayState.hx",17,0xb30d7781)
HX_STACK_THIS(this)
HX_STACK_ARG(MaxSize,"MaxSize")
{
	HX_STACK_LINE(17)
	super::__construct(MaxSize);
}
;
	return null();
}

//PlayState_obj::~PlayState_obj() { }

Dynamic PlayState_obj::__CreateEmpty() { return  new PlayState_obj; }
hx::ObjectPtr< PlayState_obj > PlayState_obj::__new(Dynamic MaxSize)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(MaxSize);
	return result;}

Dynamic PlayState_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< PlayState_obj > result = new PlayState_obj();
	result->__construct(inArgs[0]);
	return result;}

Void PlayState_obj::create( ){
{
		HX_STACK_FRAME("PlayState","create",0x82220fed,"PlayState.create","PlayState.hx",30,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(31)
		::flixel::FlxG_obj::camera->bgColor = (int)-11250604;
		HX_STACK_LINE(32)
		::Reg_obj::state = hx::ObjectPtr<OBJ_>(this);
		HX_STACK_LINE(34)
		this->addLevel();
		HX_STACK_LINE(35)
		this->addPlayer();
		HX_STACK_LINE(36)
		this->addUIText();
		HX_STACK_LINE(38)
		::Mob _g = ::Mob_obj::__new((int)120,(int)520);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(38)
		this->mob = _g;
		HX_STACK_LINE(39)
		::Mob _g1 = ::Mob_obj::__new((int)580,(int)520);		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(39)
		this->mob2 = _g1;
		HX_STACK_LINE(40)
		this->add(this->mob);
		HX_STACK_LINE(41)
		this->add(this->mob2);
		HX_STACK_LINE(43)
		this->add(this->player->bullets);
		HX_STACK_LINE(45)
		this->super::create();
	}
return null();
}


Void PlayState_obj::destroy( ){
{
		HX_STACK_FRAME("PlayState","destroy",0x6ec756e9,"PlayState.destroy","PlayState.hx",54,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(54)
		this->super::destroy();
	}
return null();
}


Void PlayState_obj::update( ){
{
		HX_STACK_FRAME("PlayState","update",0x8d182efa,"PlayState.update","PlayState.hx",61,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(62)
		this->setUIText();
		HX_STACK_LINE(64)
		::flixel::FlxG_obj::overlap(this->level,this->player,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(65)
		::flixel::FlxG_obj::overlap(this->level,this->mob,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(66)
		::flixel::FlxG_obj::overlap(this->level,this->mob2,null(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(67)
		::flixel::FlxG_obj::overlap(this->player->bullets,this->level,this->bulletHitMap_dyn(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(68)
		::flixel::FlxG_obj::overlap(this->player->bullets,this->mob,this->bulletHitMob_dyn(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(69)
		::flixel::FlxG_obj::overlap(this->player->bullets,this->mob2,this->bulletHitMob_dyn(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(70)
		::flixel::FlxG_obj::overlap(this->mob,this->player,this->enemyPlayerOverlap_dyn(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(71)
		::flixel::FlxG_obj::overlap(this->mob2,this->player,this->enemyPlayerOverlap_dyn(),::flixel::FlxObject_obj::separate_dyn());
		HX_STACK_LINE(73)
		this->super::update();
	}
return null();
}


Void PlayState_obj::addLevel( ){
{
		HX_STACK_FRAME("PlayState","addLevel",0x9a83c2d4,"PlayState.addLevel","PlayState.hx",77,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(78)
		::flixel::tile::FlxTilemap _g = ::flixel::tile::FlxTilemap_obj::__new();		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(78)
		this->level = _g;
		HX_STACK_LINE(79)
		::String _g1 = ::openfl::_v2::Assets_obj::getText(HX_CSTRING("assets/data/map.csv"));		HX_STACK_VAR(_g1,"_g1");
		HX_STACK_LINE(79)
		this->level->loadMap(_g1,HX_CSTRING("assets/images/mapTiles.png"),(int)16,(int)16,null(),null(),null(),null());
		HX_STACK_LINE(80)
		this->add(this->level);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,addLevel,(void))

Void PlayState_obj::addPlayer( ){
{
		HX_STACK_FRAME("PlayState","addPlayer",0x2c2fe411,"PlayState.addPlayer","PlayState.hx",84,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(85)
		::Player _g = ::Player_obj::__new((::flixel::FlxG_obj::width * 0.5),(int)520);		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(85)
		this->player = _g;
		HX_STACK_LINE(86)
		this->add(this->player);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,addPlayer,(void))

Void PlayState_obj::addUIText( ){
{
		HX_STACK_FRAME("PlayState","addUIText",0xfc4b81b1,"PlayState.addUIText","PlayState.hx",90,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(91)
		::flixel::text::FlxText _g = ::flixel::text::FlxText_obj::__new((int)0,(int)580,::flixel::FlxG_obj::width,null(),null(),null());		HX_STACK_VAR(_g,"_g");
		HX_STACK_LINE(91)
		this->healthText = _g;
		HX_STACK_LINE(92)
		this->healthText->scrollFactor->set(null(),null());
		HX_STACK_LINE(93)
		this->healthText->setFormat(null(),(int)8,(int)14610134,HX_CSTRING("right"),(int)1,(int)5130830,null());
		HX_STACK_LINE(94)
		this->add(this->healthText);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,addUIText,(void))

Void PlayState_obj::setUIText( ){
{
		HX_STACK_FRAME("PlayState","setUIText",0xa3cec1f2,"PlayState.setUIText","PlayState.hx",99,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_LINE(99)
		this->healthText->set_text((HX_CSTRING("HEALTH: ") + this->player->health));
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC0(PlayState_obj,setUIText,(void))

Void PlayState_obj::enemyPlayerOverlap( ::flixel::FlxObject mobRef,::flixel::FlxObject playerRef){
{
		HX_STACK_FRAME("PlayState","enemyPlayerOverlap",0xcd5f5d2f,"PlayState.enemyPlayerOverlap","PlayState.hx",103,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(mobRef,"mobRef")
		HX_STACK_ARG(playerRef,"playerRef")
		HX_STACK_LINE(104)
		hx::SubEq(playerRef->health,(int)1);
		HX_STACK_LINE(106)
		if (((playerRef->health <= (int)0))){
			HX_STACK_LINE(106)
			playerRef->kill();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,enemyPlayerOverlap,(void))

Void PlayState_obj::bulletHitMap( ::flixel::FlxObject bulletRef,::flixel::FlxObject mapRef){
{
		HX_STACK_FRAME("PlayState","bulletHitMap",0x3db4899c,"PlayState.bulletHitMap","PlayState.hx",111,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bulletRef,"bulletRef")
		HX_STACK_ARG(mapRef,"mapRef")
		HX_STACK_LINE(111)
		this->player->bullets->remove(bulletRef,null());
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,bulletHitMap,(void))

Void PlayState_obj::bulletHitMob( ::flixel::FlxObject bulletRef,::flixel::FlxObject mobRef){
{
		HX_STACK_FRAME("PlayState","bulletHitMob",0x3db495c0,"PlayState.bulletHitMob","PlayState.hx",115,0xb30d7781)
		HX_STACK_THIS(this)
		HX_STACK_ARG(bulletRef,"bulletRef")
		HX_STACK_ARG(mobRef,"mobRef")
		HX_STACK_LINE(116)
		this->player->bullets->remove(bulletRef,null());
		HX_STACK_LINE(117)
		hx::SubEq(mobRef->health,(int)20);
		HX_STACK_LINE(119)
		if (((mobRef->health <= (int)0))){
			HX_STACK_LINE(119)
			mobRef->kill();
		}
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC2(PlayState_obj,bulletHitMob,(void))


PlayState_obj::PlayState_obj()
{
}

void PlayState_obj::__Mark(HX_MARK_PARAMS)
{
	HX_MARK_BEGIN_CLASS(PlayState);
	HX_MARK_MEMBER_NAME(level,"level");
	HX_MARK_MEMBER_NAME(player,"player");
	HX_MARK_MEMBER_NAME(healthText,"healthText");
	HX_MARK_MEMBER_NAME(mob,"mob");
	HX_MARK_MEMBER_NAME(mob2,"mob2");
	::flixel::FlxState_obj::__Mark(HX_MARK_ARG);
	HX_MARK_END_CLASS();
}

void PlayState_obj::__Visit(HX_VISIT_PARAMS)
{
	HX_VISIT_MEMBER_NAME(level,"level");
	HX_VISIT_MEMBER_NAME(player,"player");
	HX_VISIT_MEMBER_NAME(healthText,"healthText");
	HX_VISIT_MEMBER_NAME(mob,"mob");
	HX_VISIT_MEMBER_NAME(mob2,"mob2");
	::flixel::FlxState_obj::__Visit(HX_VISIT_ARG);
}

Dynamic PlayState_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"mob") ) { return mob; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mob2") ) { return mob2; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"level") ) { return level; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"player") ) { return player; }
		if (HX_FIELD_EQ(inName,"create") ) { return create_dyn(); }
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"destroy") ) { return destroy_dyn(); }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"addLevel") ) { return addLevel_dyn(); }
		break;
	case 9:
		if (HX_FIELD_EQ(inName,"addPlayer") ) { return addPlayer_dyn(); }
		if (HX_FIELD_EQ(inName,"addUIText") ) { return addUIText_dyn(); }
		if (HX_FIELD_EQ(inName,"setUIText") ) { return setUIText_dyn(); }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"healthText") ) { return healthText; }
		break;
	case 12:
		if (HX_FIELD_EQ(inName,"bulletHitMap") ) { return bulletHitMap_dyn(); }
		if (HX_FIELD_EQ(inName,"bulletHitMob") ) { return bulletHitMob_dyn(); }
		break;
	case 18:
		if (HX_FIELD_EQ(inName,"enemyPlayerOverlap") ) { return enemyPlayerOverlap_dyn(); }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic PlayState_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 3:
		if (HX_FIELD_EQ(inName,"mob") ) { mob=inValue.Cast< ::Mob >(); return inValue; }
		break;
	case 4:
		if (HX_FIELD_EQ(inName,"mob2") ) { mob2=inValue.Cast< ::Mob >(); return inValue; }
		break;
	case 5:
		if (HX_FIELD_EQ(inName,"level") ) { level=inValue.Cast< ::flixel::tile::FlxTilemap >(); return inValue; }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"player") ) { player=inValue.Cast< ::Player >(); return inValue; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"healthText") ) { healthText=inValue.Cast< ::flixel::text::FlxText >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void PlayState_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("level"));
	outFields->push(HX_CSTRING("player"));
	outFields->push(HX_CSTRING("healthText"));
	outFields->push(HX_CSTRING("mob"));
	outFields->push(HX_CSTRING("mob2"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsObject /*::flixel::tile::FlxTilemap*/ ,(int)offsetof(PlayState_obj,level),HX_CSTRING("level")},
	{hx::fsObject /*::Player*/ ,(int)offsetof(PlayState_obj,player),HX_CSTRING("player")},
	{hx::fsObject /*::flixel::text::FlxText*/ ,(int)offsetof(PlayState_obj,healthText),HX_CSTRING("healthText")},
	{hx::fsObject /*::Mob*/ ,(int)offsetof(PlayState_obj,mob),HX_CSTRING("mob")},
	{hx::fsObject /*::Mob*/ ,(int)offsetof(PlayState_obj,mob2),HX_CSTRING("mob2")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("level"),
	HX_CSTRING("player"),
	HX_CSTRING("healthText"),
	HX_CSTRING("mob"),
	HX_CSTRING("mob2"),
	HX_CSTRING("create"),
	HX_CSTRING("destroy"),
	HX_CSTRING("update"),
	HX_CSTRING("addLevel"),
	HX_CSTRING("addPlayer"),
	HX_CSTRING("addUIText"),
	HX_CSTRING("setUIText"),
	HX_CSTRING("enemyPlayerOverlap"),
	HX_CSTRING("bulletHitMap"),
	HX_CSTRING("bulletHitMob"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(PlayState_obj::__mClass,"__mClass");
};

#endif

Class PlayState_obj::__mClass;

void PlayState_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("PlayState"), hx::TCanCast< PlayState_obj> ,sStaticFields,sMemberFields,
	&__CreateEmpty, &__Create,
	&super::__SGetClass(), 0, sMarkStatics
#ifdef HXCPP_VISIT_ALLOCS
    , sVisitStatics
#endif
#ifdef HXCPP_SCRIPTABLE
    , sMemberStorageInfo
#endif
);
}

void PlayState_obj::__boot()
{
}

