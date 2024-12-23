//restroom.h

//Sample for room: ��Ϣ��
//coded by zouwenbin
//data: 2000-11-16

ROOM_BEGIN(CRBaiTuoShan_restroom);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ϣ��");


	add_door("����ɽ����", "����ɽ����", "����ɽ��Ϣ��");

	set("long", "�����Ǽ���Ϣ�ң��������Ŵ󴲡�������˯���ǳ������û���ܴ��š����������ɵĳ��ȡ�");  
    set("sleep_room", 1);
    set("no_fight",1);
    set("no_steal",1);
    set("no_clean_up", 0l);

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
