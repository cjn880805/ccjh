//liangong.h

//Sample for room: ��Ĺ������
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_liangong);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ĺ������");

	add_door("��Ĺ��Ϣ��", "��Ĺ��Ϣ��", "��Ĺ������");
	add_door("��Ĺ����", "��Ĺ����", "��Ĺ������");

    set("long","����ʯ����״�������أ�ǰխ�����Ϊ���Σ����߰�Բ������ȴ��������״��ԭ��������ǰ������ʦ�������ң�ǰխ���ƣ����ʹȭ����Բ�н������Ƿ��ڡ�" );
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
