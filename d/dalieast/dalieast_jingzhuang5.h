//jingzhuang5.h

//Sample for room: �����Ǿ���5
//coded by zouwenbin
//data: 2000-11-23

ROOM_BEGIN(CRDaliEast_jingzhuang5);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "�����Ǿ���5");


//	add_door("�����Ǿ���4", "�����Ǿ���4", "�����Ǿ���5");
//	add_door("�����Ǿ���6", "�����Ǿ���6", "�����Ǿ���5");

	set("long", "��״���������Ľǹ��л�ͭ�����ա���ֻ���գ��ڽ�����һö��ͷ�п׵�ͭ�ܣ������н�����Ƭ���տڡ��վ����ո����ǿ��ġ�ÿ�����紵������������ͭ�ܣ����ո��ڿ�����������㷢���ö������С�����ƽ�����յ��������գ��������ܹ��ɽ��ǵľ�տ���ա�" );
	
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