//woyunan.h

//Sample for room:  ����������
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_woyunan);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");

	add_npc("emei_xuan");	

	add_door("���ҽ�", "���ҽ�", "����������");
	add_door("���Ҷù�̨", "���Ҷù�̨", "����������");
//	add_door("���һ�����", "���һ�����", "����������");

	set("long","�������Ա��и�����Ȫ����˵��ǰ������ˮ�˶���ɺԣ�����Ϊ֮�о�������Ȫˮ���������������ֱ��Ƕù�̨���Ա��ǻ����֡�");

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
