//longhongdong.h

//Sample for room: ����������
//coded by zouwenbin
//data: 2000-11-24

ROOM_BEGIN(CRhangzhou_longhongdong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����������");
	
	add_npc("pub_jianke");    // add by zdn 2001-07-14


	add_door("���ݷ�����", "���ݷ�����", "����������");
	add_door("��������", "��������", "����������");

	set("long","�ֽ�ͨ�춴���ڶ��ڵ��ұ��Ͽ�����̬���죬һ�ɶ�ߵķ����������·������鸡��ǰһ���������ɮȡ���Ĺ��£���һ��Ϊ�����Ծ������С��÷�����������Ħ�ڡ���������������ɽ��·��С·����������������" );

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
