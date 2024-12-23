//situ.h

//Sample for room: ˾ͽ��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_situ);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "˾ͽ��");

	add_npc("dali_huahegen");	

	add_door("�������������", "�������������", "���������˾ͽ��");

	set("long", "�����Ǵ����˾ͽ�á�������������������������Բ����ԡ������������ֵ��ǵ��Ͻ��仹����Щ������������֮������¡�" );

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
