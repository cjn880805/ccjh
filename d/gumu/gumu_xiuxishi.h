//xiuxishi.h

//Sample for room: ��Ĺ��Ϣ��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_xiuxishi);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ĺ��Ϣ��");


	add_door("��Ĺǰ��", "��Ĺǰ��", "��Ĺ��Ϣ��");
	add_door("��Ĺ������", "��Ĺ������", "��Ĺ��Ϣ��");

    set("long","���Ǽ�ܴ�ķ��䣬���߷ǳ��谵������û��ʲô��Ķ�����ֻ���м����һ����ʰ����������Ĵ󴲣����ϵı���Ҳ������������࣬���ž�������˯����" );
    set("sleep_room",1);
    set("no_fight",1);
    set("no_steal",1);
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