//tusiyishi.h

//Sample for room: ������
//coded by zouwenbin
//data: 2000-11-15

ROOM_BEGIN(CRDali_tusiyishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������");

	//add npcs into the room
	add_npc("dali_datusi");/////////////////////////
	add_npc("pub_zutouren");

	add_door("�������˾��", "�������˾��", "�������˾��������");

	set("long", "���������������裬���³����ŵ����桢ì��ꪵȱ����������Ĵ�¥���£�������ʵ�����ÿ���ǰ�����һ�������������������Ϣ��" );

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
