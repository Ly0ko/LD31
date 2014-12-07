#ifndef INCLUDED_Player
#define INCLUDED_Player

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxSprite.h>
HX_DECLARE_CLASS0(Bullet)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,system,FlxSound)
HX_DECLARE_CLASS2(flixel,tweens,FlxTween)


class HXCPP_CLASS_ATTRIBUTES  Player_obj : public ::flixel::FlxSprite_obj{
	public:
		typedef ::flixel::FlxSprite_obj super;
		typedef Player_obj OBJ_;
		Player_obj();
		Void __construct(Float x,Float y);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< Player_obj > __new(Float x,Float y);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~Player_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("Player"); }

		int _maxSpeed;
		int _maxAcceleration;
		int _drag;
		int _gravity;
		int _maxFallSpeed;
		int _jumpforce;
		int _health;
		::flixel::group::FlxGroup bullets;
		::Bullet bullet;
		int bulletDelay;
		::flixel::system::FlxSound _shootSound;
		virtual Void update( );

		virtual Void kill( );

		virtual Void finishKill( ::flixel::tweens::FlxTween _);
		Dynamic finishKill_dyn();

		virtual Void controls( );
		Dynamic controls_dyn();

		virtual Void levelConstraints( );
		Dynamic levelConstraints_dyn();

};


#endif /* INCLUDED_Player */ 
