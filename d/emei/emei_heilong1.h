//heilong1.h

//Sample for room:  ���Һ�����ջ��
//coded by zouwenbin
//data: 2000-11-30

ROOM_BEGIN(CREMei_heilong1);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "���Һ�����ջ��");

	add_npc("pub_youke");
        add_npc("pub_daoke");   // add by zdn 2001-07-13
				
	add_door("����������", "����������", "���Һ�����ջ��");
	add_door("����ǧ����", "����ǧ����", "���Һ�����ջ��");

	set("long","������ջ���غ���������������һɽ�п������²������γ�һ��������ߣ����Ｘ���׵���Ͽ��������Ͽ��������ջ���ʹ���խ�İ���Ͽ��ת�۴����������ھ����ϡ�����ջ���ϣ�ֻ����խ��Σ�������������������ɽ��������������ͷ���������϶���¿������ϡ�������쿪��ͼ�ġ�һ���졹��ջ����ͨǧ���֣�����������(shibei)���ɴ������ϣ������Ǻ�����ջ������·������������ȥ�з��¡�");
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
