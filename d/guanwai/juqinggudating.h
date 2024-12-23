//juqinggudating.h 绝情谷大厅
//秦波 2002.3.8

ROOM_BEGIN(CRjuqinggudating);

virtual void create()			
{
	set_name("绝情谷大厅");
	add_npc("pub_gongsunzhi");   
//	add_npc("pub_boy");

	add_door("绝情谷山道", "绝情谷山道", "绝情谷大厅");
   
};

ROOM_END;




