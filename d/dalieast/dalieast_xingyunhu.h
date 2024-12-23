//xingyunhu.h

//Sample for room: ��������ƺ���
//coded by zouwenbin
//data: 2000-11-23

RESIDENT_BEGIN(CRDaliEast_xingyunhu);

virtual void create()			//Call it when Room Create
{
	//set name of our room
	set_name( "��������ƺ���");

	set("resident", "���۲�");

	add_npc("pub_playboy");
	add_npc("pub_boy");       //add by zdn 2001-07-12

	add_door("����ǲ��۲�", "����ǲ��۲�", "��������ƺ���");
	add_door("�������ϼɽ", "�������ϼɽ", "��������ƺ���");

	set("long", "���ƺ�����С��������Բ��ʮ���������ϼɽ����ˮ�峺��������ģ����Ǵ���������������֮ҹ������¹�ӳ�պ��棬���ˮ����ҡҷ���ˣ��緱��������У��������ƣ�����֮���ڴ�Զ����֮���ϰ����ɼ�����������з����������С�" );
	
};

virtual int do_look(CChar * me)
{
	char msg[255];
	CContainer * yinyue_si;
	yinyue_si=me->present("yingyue si");
	snprintf(msg, 255, "%s", querystr("long"));
	say(msg, me);
	if(me->querymap("xy") && !me->query("xy/renwu1") && yinyue_si)
	{
		say("�㿴�����߲���һҶС�ۡ�", me);
		AddMenuItem("����", "$0huachuan $1", me);
	}
	SendMenu(me);
	return 1;
}

virtual int handle_action(char *comm, CChar *me, char * arg, char * tar)
{
	CContainer * yinyue_si;
	yinyue_si=me->present("yingyue si");
	if(me->querymap("xy") && !me->query("xy/renwu1") && yinyue_si)
	{
		if(strcmp(comm, "huachuan") == 0)
			return do_huachuan(me, arg);
		if(strcmp(comm, "you") == 0)
			return do_you(me, arg);
	}
	return 0;
}

int do_huachuan(CChar *me, char * arg)
{
	say("��ʱ�ѽ�������µ��գ����ۺ��ϣ�ֻ����ϼɽ��������ң��������࣬�̲���Ҷ�໥ӳ�ģ�Ҳ��Ӧ�ˡ���ϼ���������ˣ��������ޱ̾�ǰ�����⾳���Ͳ�֪���������к���ָ��", me);
	say("���������У��������ţ�������˯ȥ��", me);
	say("˯�μ䣬����һ�ɺ���ֱ�������������ת������˫�ۣ���һ����ͬС�ɣ������Լ��������ں�ˮ֮�С�", me);
	if(me->query_skill("beiming_shengong",1))
		say("�����б�ڤ�񹦻��壬����������ɥ���С�", me);
	else
		me->set("hp",100);
	AddMenuItem("��", "$0you $1", me);
	SendMenu(me);
	return 1;
}

int do_you(CChar *me, char * arg)
{
	tell_object(me,"\n$HIC��ʱ���ú�ˮ�峺�¹�͸�ף����������������ȥ��");
	tell_object(me,"$HIC���ڴ�ʱ���㻳�еġ�����֮�ס����¹��ӳ��֮�¾�����һ�������İ׹⣬�������ȥ��");
	tell_object(me,"$HIC��Ȼ�䣬���׾����ѿ��㷢������֮��������������һ���޴�����У�����Ӳ�����ľ�����ȥ��");
	tell_object(me,"$HIC�ں�ˮ�ĳ��֮�£�����ǰһ�ڣ��ʹ��λ��ȥ��\n");
	me->unconcious();
	me->set("hp",me->query("eff_hp"));
	me->move(load_room("��ң��СϪ��"));
	me->set_temp("xy/renwu2_1",1);//������ң��
	me->set_temp("no_fei_1",1);//�����ڼ䣬��ֹ����
	return 1;
}

RESIDENT_END;
