//jingzhuang5.h
//Sample for room: ����Ǿ���5

ROOM_BEGIN(CRXiaoYao_jingzhuang5);

virtual void create()
{
	set_name( "����Ǿ���5");
	set("no_autosave",1);

	add_door("����Ǿ���4", "��ң�ȴ���Ǿ���4", "��ң�ȴ���Ǿ���5");
	add_door("����Ǿ���6", "��ң�ȴ���Ǿ���6", "��ң�ȴ���Ǿ���5");

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
