//taohua.h
//Sample for room: ̨���һ�Ժ

//coded by Teapot

//data: 2000-11-4



ROOM_BEGIN(CRTaiWan_taohua);



virtual void create()			//Call it when Room Create
{
	set_name( "̨���һ�Ժ");

	set("monster_chance", 20);
	
//	add_npc("pub_lady3");    //add by zdn 2001-07-16

	add_door("̨����ͨ��", "̨����ͨ��", "̨���һ�Ժ");

	set("long", "�򹷸�λ��̨���ϲ��������С�������е����������ھ�����Ͽ�壬��ǫ̈̄��һ���ۡ�  " );
};

ROOM_END;
