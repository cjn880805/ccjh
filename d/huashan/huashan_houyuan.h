//houyuan.h

//Sample for room: ��ɽ��Ժ
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRHuaShan_houyuan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��ɽ��Ժ");
	
	add_npc("pub_lady3");           //add by zdn 2001-07-17

	add_door("��ɽ��԰", "��ɽ��԰", "��ɽ��Ժ");
	add_door("��ɽ��ɽС��", "��ɽ��ɽС��", "��ɽ��Ժ");

	set("long", "�����ǻ�ɽ�ɵĺ�Ժ�������ǻ�ɽ���ӵľ��Һ�����������ɽ��������ɽ�����������վ��������������¡���������һ��С��Ժ���м�ɽС�أ���ɫ���ˣ����н�����԰����ɫ��");  
    
 
/*****************************************************
	set("exits",([
		"northeast"  : __DIR__"garden",
		"west"       : __DIR__"jiashan",
		"east"       : __DIR__"xuanya",
	]));
********************************************/
};


ROOM_END;
