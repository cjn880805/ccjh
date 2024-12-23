//yushanfang.h

//Sample for room: ���ŷ�
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRDali_yushanfang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���ŷ�");

	//add npcs into the room
	add_npc("pub_taijian");
	
	add_door("����ǻʹ�ǰ��", "����ǻʹ�ǰ��", "����ǻʹ����ŷ�");

	set("long", "�����Ǵ�����ʹ������ŷ�������ĳ��߶��ǽ������ɵġ��ʵ۲�������Ҳ��Ϣ���ˣ������ǳ��ȡ�" );

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
