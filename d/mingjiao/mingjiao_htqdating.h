//htqdating.h



//Sample for room: ���������
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRMingJiao_htqdating);
virtual void create()			//Call it when Room Create
{
	set_name( "���̺��������");

	add_npc("mingjiao_yanyuan");
	add_npc("pub_miaofeng");
	
	add_door("������ʯ���9", "������ʯ���9", "���̺��������");

     

};

ROOM_END;
