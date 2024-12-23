//bridge.h

//Sample for room: ÌúË÷ÇÅ
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_bridge);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "ÌúË÷ÇÅ");
	
	add_npc("wanjie_zhongling");        //add by zdn 2001-07-20



	add_door("Íò½Ù¹ÈÉÆÈË¶É", "Íò½Ù¹ÈÉÆÈË¶É", "Íò½Ù¹ÈÌúË÷ÇÅ");
	add_door("Íò½Ù¹ÈÀ½²×½­ÅÏ", "Íò½Ù¹ÈÀ½²×½­ÅÏ", "Íò½Ù¹ÈÌúË÷ÇÅ");

};


ROOM_END;
