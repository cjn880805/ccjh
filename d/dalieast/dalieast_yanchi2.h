//yanchi2.h

//Sample for room: 大理城沿池堤岸2
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_yanchi2);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "大理城沿池堤岸2");

	set("resident", "罗伽甸");

	add_npc("pub_cunfu");
	add_npc("pub_bing");         //add by zdn 2001-07-12

	add_door("大理城沿池堤岸1", "大理城沿池堤岸1", "大理城沿池堤岸2");
	add_door("大理城沿池堤岸3", "大理城沿池堤岸3", "大理城沿池堤岸2");

	set("long", "滇池风景怡人，沿堤岸漫步，遵堤行湖中，堤南北皆碧水。盖其碧波即草海之余，南连于滇池，北抵黄土坡，西濒与赤鼻山之簏。东行湖中，遥顾四周山色，掩映重波间，青蒲偃水，高柳潆堤，天然绝胜。" );
	
};



RESIDENT_END;
