//caomeide.h

//Sample for room: ����ɽ��ݮ��
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_caomeide);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽ��ݮ��");

	set("monster_chance", 1);
	CBox * box = Add_Box();
	box->add_object("caomei", 1);	
	box->set_name( "����");	

	add_door("����ɽ����", "����ɽ����", "����ɽ��ݮ��");

	set("long", "������һ���ݮ�أ��ʺ�Ĳ�ݮɢ�����̲��У����˸е�������⡣");

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
