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
#ifndef INCLUDED_flixel_tweens_FlxEase
#include <flixel/tweens/FlxEase.h>
#endif
#ifndef INCLUDED_flixel_tweens_FlxTween
#include <flixel/tweens/FlxTween.h>
#endif
#ifndef INCLUDED_flixel_tweens_misc_VarTween
#include <flixel/tweens/misc/VarTween.h>
#endif
#ifndef INCLUDED_flixel_util_FlxPoint
#include <flixel/util/FlxPoint.h>
#endif

Void Mob_obj::__construct(Float x,Float y)
{
HX_STACK_FRAME("Mob","new",0x6f923f92,"Mob.new","Mob.hx",9,0xf3df581e)
HX_STACK_THIS(this)
HX_STACK_ARG(x,"x")
HX_STACK_ARG(y,"y")
{
	HX_STACK_LINE(16)
	this->_health = (int)140;
	HX_STACK_LINE(14)
	this->_maxFallSpeed = (int)800;
	HX_STACK_LINE(13)
	this->_gravity = (int)1600;
	HX_STACK_LINE(12)
	this->maxSpeed = (int)50;
	HX_STACK_LINE(20)
	super::__construct(x,y,null());
	HX_STACK_LINE(22)
	this->makeGraphic((int)16,(int)20,(int)-65536,null(),null());
	HX_STACK_LINE(23)
	this->health = this->_health;
	HX_STACK_LINE(24)
	this->velocity->set_x(this->maxSpeed);
	HX_STACK_LINE(25)
	this->maxVelocity->set_y(this->_maxFallSpeed);
	HX_STACK_LINE(26)
	this->acceleration->set_y(this->_gravity);
}
;
	return null();
}

//Mob_obj::~Mob_obj() { }

Dynamic Mob_obj::__CreateEmpty() { return  new Mob_obj; }
hx::ObjectPtr< Mob_obj > Mob_obj::__new(Float x,Float y)
{  hx::ObjectPtr< Mob_obj > result = new Mob_obj();
	result->__construct(x,y);
	return result;}

Dynamic Mob_obj::__Create(hx::DynamicArray inArgs)
{  hx::ObjectPtr< Mob_obj > result = new Mob_obj();
	result->__construct(inArgs[0],inArgs[1]);
	return result;}

Void Mob_obj::update( ){
{
		HX_STACK_FRAME("Mob","update",0x32432217,"Mob.update","Mob.hx",30,0xf3df581e)
		HX_STACK_THIS(this)
		HX_STACK_LINE(31)
		if (((::Reg_obj::state->player->x < this->x))){
			HX_STACK_LINE(31)
			this->velocity->set_x(-(this->maxSpeed));
		}
		else{
			HX_STACK_LINE(31)
			this->velocity->set_x(this->maxSpeed);
		}
		HX_STACK_LINE(33)
		this->super::update();
	}
return null();
}


Void Mob_obj::kill( ){
{
		HX_STACK_FRAME("Mob","kill",0x2e6cbc2c,"Mob.kill","Mob.hx",37,0xf3df581e)
		HX_STACK_THIS(this)
		HX_STACK_LINE(38)
		this->set_alive(false);
		HX_STACK_LINE(39)
		this->scale->set(1.5,1.5);
		struct _Function_1_1{
			inline static Dynamic Block( ){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Mob.hx",40,0xf3df581e)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("x") , (int)1,false);
					__result->Add(HX_CSTRING("y") , (int)1,false);
					return __result;
				}
				return null();
			}
		};
		struct _Function_1_2{
			inline static Dynamic Block( hx::ObjectPtr< ::Mob_obj > __this){
				HX_STACK_FRAME("*","closure",0x5bdab937,"*.closure","Mob.hx",40,0xf3df581e)
				{
					hx::Anon __result = hx::Anon_obj::Create();
					__result->Add(HX_CSTRING("ease") , ::flixel::tweens::FlxEase_obj::elasticOut_dyn(),false);
					__result->Add(HX_CSTRING("complete") , __this->finishKill_dyn(),false);
					return __result;
				}
				return null();
			}
		};
		HX_STACK_LINE(40)
		::flixel::tweens::FlxTween_obj::tween(this->scale,_Function_1_1::Block(),0.5,_Function_1_2::Block(this));
		HX_STACK_LINE(41)
		this->acceleration->set_y((int)1200);
		HX_STACK_LINE(42)
		this->velocity->set_y((int)-200);
		HX_STACK_LINE(43)
		this->allowCollisions = (int)0;
	}
return null();
}


Void Mob_obj::finishKill( ::flixel::tweens::FlxTween _){
{
		HX_STACK_FRAME("Mob","finishKill",0xf31c2c9f,"Mob.finishKill","Mob.hx",48,0xf3df581e)
		HX_STACK_THIS(this)
		HX_STACK_ARG(_,"_")
		HX_STACK_LINE(48)
		this->set_exists(false);
	}
return null();
}


HX_DEFINE_DYNAMIC_FUNC1(Mob_obj,finishKill,(void))


Mob_obj::Mob_obj()
{
}

Dynamic Mob_obj::__Field(const ::String &inName,bool inCallProp)
{
	switch(inName.length) {
	case 4:
		if (HX_FIELD_EQ(inName,"kill") ) { return kill_dyn(); }
		break;
	case 6:
		if (HX_FIELD_EQ(inName,"update") ) { return update_dyn(); }
		break;
	case 7:
		if (HX_FIELD_EQ(inName,"_health") ) { return _health; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxSpeed") ) { return maxSpeed; }
		if (HX_FIELD_EQ(inName,"_gravity") ) { return _gravity; }
		break;
	case 10:
		if (HX_FIELD_EQ(inName,"finishKill") ) { return finishKill_dyn(); }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_maxFallSpeed") ) { return _maxFallSpeed; }
	}
	return super::__Field(inName,inCallProp);
}

Dynamic Mob_obj::__SetField(const ::String &inName,const Dynamic &inValue,bool inCallProp)
{
	switch(inName.length) {
	case 7:
		if (HX_FIELD_EQ(inName,"_health") ) { _health=inValue.Cast< int >(); return inValue; }
		break;
	case 8:
		if (HX_FIELD_EQ(inName,"maxSpeed") ) { maxSpeed=inValue.Cast< int >(); return inValue; }
		if (HX_FIELD_EQ(inName,"_gravity") ) { _gravity=inValue.Cast< int >(); return inValue; }
		break;
	case 13:
		if (HX_FIELD_EQ(inName,"_maxFallSpeed") ) { _maxFallSpeed=inValue.Cast< int >(); return inValue; }
	}
	return super::__SetField(inName,inValue,inCallProp);
}

void Mob_obj::__GetFields(Array< ::String> &outFields)
{
	outFields->push(HX_CSTRING("maxSpeed"));
	outFields->push(HX_CSTRING("_gravity"));
	outFields->push(HX_CSTRING("_maxFallSpeed"));
	outFields->push(HX_CSTRING("_health"));
	super::__GetFields(outFields);
};

static ::String sStaticFields[] = {
	String(null()) };

#if HXCPP_SCRIPTABLE
static hx::StorageInfo sMemberStorageInfo[] = {
	{hx::fsInt,(int)offsetof(Mob_obj,maxSpeed),HX_CSTRING("maxSpeed")},
	{hx::fsInt,(int)offsetof(Mob_obj,_gravity),HX_CSTRING("_gravity")},
	{hx::fsInt,(int)offsetof(Mob_obj,_maxFallSpeed),HX_CSTRING("_maxFallSpeed")},
	{hx::fsInt,(int)offsetof(Mob_obj,_health),HX_CSTRING("_health")},
	{ hx::fsUnknown, 0, null()}
};
#endif

static ::String sMemberFields[] = {
	HX_CSTRING("maxSpeed"),
	HX_CSTRING("_gravity"),
	HX_CSTRING("_maxFallSpeed"),
	HX_CSTRING("_health"),
	HX_CSTRING("update"),
	HX_CSTRING("kill"),
	HX_CSTRING("finishKill"),
	String(null()) };

static void sMarkStatics(HX_MARK_PARAMS) {
	HX_MARK_MEMBER_NAME(Mob_obj::__mClass,"__mClass");
};

#ifdef HXCPP_VISIT_ALLOCS
static void sVisitStatics(HX_VISIT_PARAMS) {
	HX_VISIT_MEMBER_NAME(Mob_obj::__mClass,"__mClass");
};

#endif

Class Mob_obj::__mClass;

void Mob_obj::__register()
{
	hx::Static(__mClass) = hx::RegisterClass(HX_CSTRING("Mob"), hx::TCanCast< Mob_obj> ,sStaticFields,sMemberFields,
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

void Mob_obj::__boot()
{
}

