//qianting.h

//Sample for room: ��Ĺǰ��
//coded by zouwenbin
//data: 2000-11-17

ROOM_BEGIN(CRGuMu_qianting);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��Ĺǰ��");


	add_door("��ĹĹ��", "��ĹĹ��", "��Ĺǰ��");
	add_door("��ĹС��", "��ĹС��", "��Ĺǰ��");
	add_door("��Ĺ��Ϣ��", "��Ĺ��Ϣ��", "��Ĺǰ��");

    set("long","�����ǹ�Ĺ��ǰ����������ģ��㼸��ʲôҲ�����塣ȫ���������м������������һ��ҹ���飬ӳ��������Ļƹ⡣����������˶���ʯ�����ɵģ������ƺ���д��һЩʲô��--����ôҲ��������ˡ�" );
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
