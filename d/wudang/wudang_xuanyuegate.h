//xuanyuegate.h

//Sample for room: �䵱������
//coded by zouwenbin
//data: 2000-11-29

ROOM_BEGIN(CRWuDang_xuanyuegate);

virtual void create()			//Call it when Room Create
{
	set_name( "�䵱������");

	add_npc("wudang_zhike");
	add_npc("wudang_daotong");

	add_door("�䵱�⽣��", "�䵱�⽣��", "�䵱������");
	add_door("�䵱���湬", "�䵱���湬", "�䵱������");

};


ROOM_END;
