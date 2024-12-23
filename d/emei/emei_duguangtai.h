//duguangtai.h

//Sample for room:  ���Ҷù�̨
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_duguangtai);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Ҷù�̨");

	add_npc("emei_bei");

	add_door("����������", "����������", "���Ҷù�̨");
	add_door("���һ�����", "���һ�����", "���Ҷù�̨");

	set("long","�����ǿ��ճ����ƺ�����⡢���֮�ء�̨���������ɣ������޵ף��������ڡ���Ŀ��������������Ĵ�Сѩɽ��������Ŀ���������ƺ�������ãã��������Ұ��Զ����ʡ��ƺ��ᵴʱ�����ڽ𶥣���̤���ƣ�����ƮƮ����֮�У�������Ѹ��ӿ��ʱ�������𶥶�������ǰ�����������г�������֮�⡣");
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




