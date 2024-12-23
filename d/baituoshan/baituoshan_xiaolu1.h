//xiaolu1.h

//Sample for room: ����ɽС·1
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_xiaolu1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽС·1");
	
	set("monster_chance", 1);

	add_door("����ɽ�ص�", "����ɽ�ص�", "����ɽС·1");
	add_door("����ɽ����", "����ɽ����", "����ɽС·1");
	add_door("����ɽС·2", "����ɽС·2", "����ɽС·1");

	set("long", "������һ����ɽ��С·��");
    
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
