//chongyanggong.h

//Sample for room:  ÷ÿ—Ùπ¨
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "÷ÿ—Ùπ¨");

	add_npc("quanzhen_cheng");
	add_npc("quanzhen_cui");
	add_npc("quanzhen_fang");
	add_npc("quanzhen_hao");
	add_npc("quanzhen_qiu");

	add_door("÷ÿ—Ùπ¨¥Û√≈", "÷ÿ—Ùπ¨¥Û√≈", "÷ÿ—Ùπ¨");

	add_door("÷ÿ—Ùπ¨…≈Ã√", "÷ÿ—Ùπ¨…≈Ã√", "÷ÿ—Ùπ¨");
	add_door("÷ÿ—Ùπ¨”ˆ’Êπ¨", "÷ÿ—Ùπ¨”ˆ’Êπ¨", "÷ÿ—Ùπ¨");
	add_door("÷ÿ—Ùπ¨¡∑π¶∑ø", "÷ÿ—Ùπ¨¡∑π¶∑ø", "÷ÿ—Ùπ¨");
	add_door("÷ÿ—Ùπ¨æ≤–ﬁ “", "÷ÿ—Ùπ¨æ≤–ﬁ “", "÷ÿ—Ùπ¨");
	add_door("÷ÿ—Ùπ¨œ‘’ÊÃ√", "÷ÿ—Ùπ¨œ‘’ÊÃ√", "÷ÿ—Ùπ¨");
	add_door("÷ÿ—Ùπ¨–›œ¢ “", "÷ÿ—Ùπ¨–›œ¢ “", "÷ÿ—Ùπ¨");
	add_door("÷ÿ—Ùπ¨–°ª®‘∞1", "÷ÿ—Ùπ¨–°ª®‘∞1", "÷ÿ—Ùπ¨");



/******************************************************************************
 ******************************************************************************/
};

ROOM_END;
//last, register the room into ../server/RoomSetup.cpp