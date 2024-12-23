//xianzhentang.h

//Sample for room:  ������������
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_xianzhentang);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "������������");

	add_door("������", "������", "������������");
	
	add_npc("quanzhen_zhang");


	set("long", "�����Ǵ����Աߵ�һ��������Ҳ�ǽӴ���Ҫ���˵ĵط���������ֻ�ڷ���һ�����Ӻͼ������ӡ����ϰڷ���һ���ɽ��ˮ���辰��ǽ���Ϲ���һЩ�ֻ���������һ��ҩ���ң�����ҩ�ĵط���");

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
//last, register the room into ../server/RoomSetup.cpp