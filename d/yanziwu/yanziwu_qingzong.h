//qingzong.h

//Sample for room: ��������ڣ
//coded by zouwenbin
//data: 2000-11-13

ROOM_BEGIN(CRyanziwu_qingzong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������ڣ");

	add_door("����������", "����������", "��������ڣ");

    set("long", "�������������ư��ƣ���Ȼ��Ȼ���ʣ�ԭ������Ľ�����ҵ�Ĺ�أ���˵����������˾����ڴ��ˡ����ϳ�����ϸ��С�ݣ���˵���ֲݳ�����̣�������ή���ƺ�����������һƬ��������޳��ڡ�" );
    
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