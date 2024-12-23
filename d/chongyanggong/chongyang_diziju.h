//diziju.h

//Sample for room:  ���������Ӿ�
//coded by zouwenbin
//data: 2000-12-2

ROOM_BEGIN(CRChongYang_diziju);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���������Ӿ�");

	add_door("������������", "������������", "���������Ӿ�");
	add_npc("quanzhen_zhangjing");

	set("long", "������ȫ��̵��Ӿ�ס�ķ��䡣����ܴ����������һ��һ�ŵĴ������ϱ��춼�۵����������룬����һ���˶�û�У�Ҳ�����еĵ��Ӷ�ȥ����ȥ�ˡ���ǽ�ĵط���һ������(cabinet)��");

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