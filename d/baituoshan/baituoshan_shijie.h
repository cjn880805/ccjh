//shijie.h

//Sample for room: ����ɽʯ��
//coded by zouwenbin
//data: 2000-11-28

ROOM_BEGIN(CRBaiTuoShan_shijie);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����ɽʯ��");


	add_door("����ɽ�㳡", "����ɽ�㳡", "����ɽʯ��");
	add_door("����ɽ��ƺ", "����ɽ��ƺ", "����ɽʯ��");
	add_door("����ɽ����", "����ɽ����", "����ɽʯ��");

	set("long", "��������ʯ���̳ɵ�ʯ���ϡ�������Ǵ�˵�����صİ���ɽ��ԶԶ��ȥ��������ɳ�ѻ��γɵ�ɽ�����һֻ���յļ�����һ��ɽ�����������ǰ��(door)�ر��š������ǡ�����ɽׯ���Ĵ������ϱ߾��Ǵ����ˡ�");

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
