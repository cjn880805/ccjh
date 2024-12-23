//wangfugate.h

//Sample for room: ��������
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_wangfugate);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������");

	//add npcs into the room
	add_npc("pub_weishi2");/////////////////////////
	add_npc("pub_weishi1");

	add_npc("pub_xiangke");
	add_npc("dali_fusigui");
	add_npc("dali_jiading");
	add_npc("dali_bing");      //add by zdn 2001-07-20
				

	add_door("����Ƕ�", "����Ƕ�", "�������������");
	add_door("�������������", "�������������", "�������������");

	set("long", "����վ��һ�������ĸ���ǰ����ǰ����ֻ�����ʯʨ�ӣ����ϸ���һ����ң����顸�����������ĸ����֡��ſ�վ���������������Ž��£���ִ�ֵ�������������" );
	set("valid_startroom", 1);

};

virtual int do_look(CChar * me)
{
	char msg[255];
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	SendMenu(me);
	return 1;
}
ROOM_END;




