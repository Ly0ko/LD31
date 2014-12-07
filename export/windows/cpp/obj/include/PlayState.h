#ifndef INCLUDED_PlayState
#define INCLUDED_PlayState

#ifndef HXCPP_H
#include <hxcpp.h>
#endif

#include <flixel/FlxState.h>
HX_DECLARE_CLASS0(Mob)
HX_DECLARE_CLASS0(PlayState)
HX_DECLARE_CLASS0(Player)
HX_DECLARE_CLASS1(flixel,FlxBasic)
HX_DECLARE_CLASS1(flixel,FlxObject)
HX_DECLARE_CLASS1(flixel,FlxSprite)
HX_DECLARE_CLASS1(flixel,FlxState)
HX_DECLARE_CLASS2(flixel,group,FlxGroup)
HX_DECLARE_CLASS2(flixel,group,FlxTypedGroup)
HX_DECLARE_CLASS2(flixel,interfaces,IFlxDestroyable)
HX_DECLARE_CLASS2(flixel,text,FlxText)
HX_DECLARE_CLASS2(flixel,tile,FlxTilemap)
HX_DECLARE_CLASS2(flixel,util,FlxTimer)


class HXCPP_CLASS_ATTRIBUTES  PlayState_obj : public ::flixel::FlxState_obj{
	public:
		typedef ::flixel::FlxState_obj super;
		typedef PlayState_obj OBJ_;
		PlayState_obj();
		Void __construct(Dynamic MaxSize);

	public:
		inline void *operator new( size_t inSize, bool inContainer=true)
			{ return hx::Object::operator new(inSize,inContainer); }
		static hx::ObjectPtr< PlayState_obj > __new(Dynamic MaxSize);
		static Dynamic __CreateEmpty();
		static Dynamic __Create(hx::DynamicArray inArgs);
		//~PlayState_obj();

		HX_DO_RTTI;
		static void __boot();
		static void __register();
		void __Mark(HX_MARK_PARAMS);
		void __Visit(HX_VISIT_PARAMS);
		::String __ToString() const { return HX_CSTRING("PlayState"); }

		::flixel::tile::FlxTilemap level;
		::Player player;
		::flixel::text::FlxText healthText;
		::flixel::group::FlxGroup waves;
		::Mob mob;
		virtual Void create( );

		virtual Void destroy( );

		virtual Void update( );

		virtual Void addLevel( );
		Dynamic addLevel_dyn();

		virtual Void addPlayer( );
		Dynamic addPlayer_dyn();

		virtual Void addWave( ::flixel::util::FlxTimer _);
		Dynamic addWave_dyn();

		virtual Void addUIText( );
		Dynamic addUIText_dyn();

		virtual Void setUIText( );
		Dynamic setUIText_dyn();

		virtual Void enemyPlayerOverlap( ::flixel::FlxObject mobRef,::flixel::FlxObject playerRef);
		Dynamic enemyPlayerOverlap_dyn();

		virtual Void bulletHitMap( ::flixel::FlxObject bulletRef,::flixel::FlxObject mapRef);
		Dynamic bulletHitMap_dyn();

		virtual Void bulletHitMob( ::flixel::FlxObject bulletRef,::flixel::FlxObject mobRef);
		Dynamic bulletHitMob_dyn();

};


#endif /* INCLUDED_PlayState */ 
