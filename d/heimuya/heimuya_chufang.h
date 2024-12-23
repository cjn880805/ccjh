//chufang.h

//Sample for room: ∫⁄ƒæ—¬∞◊ª¢Ã√≥¯∑ø
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRHeiMuYa_chufang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "∫⁄ƒæ—¬∞◊ª¢Ã√≥¯∑ø");

        add_npc("pub_cunfu");     // add by zdn 2001-07-14

	add_door("∫⁄ƒæ—¬∞◊ª¢Ã√", "∫⁄ƒæ—¬∞◊ª¢Ã√", "∫⁄ƒæ—¬∞◊ª¢Ã√≥¯∑ø");

	set("long", "’‚ « •π√Ã√µƒ≥¯∑ø£¨“ªŒª√¿¿ˆ Ã≈Æ¬˙¡≥∂—–¶°£’˚∏ˆ∑øº‰≤Àœ„ÎŸ÷¨œ„√‘¬˛°£«Ω…œÃ˘◊≈“ª’≈–—ƒøµƒ∆Ù ¬(note)°£");

/*****************************************************
  set("exits",([
      "west" : __DIR__"chitang",
  ]));
  set("item_desc",([
      "note" : "◊Óƒ—œ˚ ‹≈Æ»À∏££¨∫Ï—’ªˆÀÆ°£----->‘¿≤ª»∫Ã‚\n",
  ]));

  set("objects",([
      __DIR__"npc/shinu" : 1,
      __DIR__"obj/tea" : random(6),
      __DIR__"obj/sherou"  : random(4),
  ]));
//  
********************************************/
};


ROOM_END;
