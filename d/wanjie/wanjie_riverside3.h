//riverside3.h

//Sample for room: ����С·3
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRWanJie_riverside3);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "����С·3");


	add_door("��ٹȽ���С·2", "��ٹȽ���С·2", "��ٹȽ���С·3");
	add_door("��ٹ����˶�", "��ٹ����˶�", "��ٹȽ���С·3");

	set("long","�������׽��ߵ�һ��С·����ˮ���ϣ������汼�ڶ����������ϲ�ʱ���������ĺ��������뽭��ĺ�Х���γ�һ�����˵Ľ�����");
    
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
