//heifengkou.h

//Sample for room: �ڷ��
//coded by zouwenbin
//data: 2000-12-1

ROOM_BEGIN(CRGuanWai_heifengkou);

virtual void create()			
{
	set_name( "�ڷ��");

	set("monster_chance", 50);

    add_npc("guanwai_jiaowenqi"); 
	add_npc("pub_fengwuchang");
	
	add_door("��������2", "��������2", "����ڷ��");
	add_door("����С���", "����С���", "����ڷ��");

	set("long","�����������е��ն�֮����Χ��Ϊï�ܵ����֣�������⡣���д���Ұ�޼���֮����˻���Ĵ��в�֪���Ĳ��Ժ�Ұ��������һ��Ҳ���ҳ�������ľ�İ����䣬�ƺ�����ɱ�����㵽�˴˴����ĵ����ѣ�ֻ�����뿪��" );

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
