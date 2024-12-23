//pub_hanxiangzi.h
//zcoya 2002-07-29

NPC_BEGIN(CNpub_hanxiangzi);

void create()
{
	set_name("������", "han xiang zi");
	
	set("title", "�˶�����");
	set("long","���˺��Ĺ�ֶ֮��Ҳ���е��������ɹǣ����Բ���ᷱ��Ũ����ϲ�����ģ�������Ů�����ܵ����ģ����Ƹ��ȣ���������־��");
	
	set("icon", young_man4);
	set("per",23);
	
	set("gender", "����");
	set("level", 300);
	set("age", 2000);
	set("no_huan",1);
}

int do_talk(CChar * me, char * ask = NULL)
{
	say("����������ʩ����������տ��֣���",me);	
	SendMenu(me);
	return 1;
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	char msg[255];
	if(EQUALSTR(ob->querystr("name"), "��Ƭ") && ob->Query_Amount() ==1
		&& EQUALSTR(ob->querystr("id"), "yu pian") )
	{
		destruct(ob);
		tell_object(me,"\n$HIC������һʩ�񣬹ĵѳ�֮��");

		tell_object(me,"$HIC��ɽ��ˮ�����˵�����ң�");
		tell_object(me,"$HIC�ְ���ϼҺ����������ϼ��");
		tell_object(me,"$HIC�ٵ����񶴣�¯������ɰ��");
		tell_object(me,"$HIC������𻢣�֥������ѻ��");

		tell_object(me,"$HICһư���컯����������а��");
		tell_object(me,"$HIC������Ѳ�ƣ��ܿ���̻���");
		tell_object(me,"$HIC������ѧ�ң�ͬ�������⡣");

		tell_object(me,"\n$HIC����ȡ������ǰ���Խ����֮�����꿪�����������ơ�");
		tell_object(me,"$HIC�־����ɶѣ�����ʱ���̻�һ�䣬��ĵ�������ɫ������");
		tell_object(me,snprintf(msg, 255,"$HIC����ӵ������һ���ƣ���ף%s���տ��֣���\n",me->name(1)));

		return 1;
	}
	if(EQUALSTR(ob->querystr("name"), "��Ƭ") && ob->Query_Amount() >=8
		&& EQUALSTR(ob->querystr("id"), "yu pian")
		&& !me->query("yuandna/han1_liwu") )
	{
		destruct(ob);
		me->set("yuandna/han1_liwu",1);
		tell_object(me,"\n$HIC������ʩ���������л������Ҳ��һ������������");
		load_item("greenxiao")->move(me);
		return 1;
	}
	return 0;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(strcmp(comm, "kill") == 0 || strcmp(comm, "fight") == 0	|| strcmp(comm, "cast") == 0)
	{
		message_vision("$n��$N���˿����Ǻ�һЦ�����ԴӶɹ�����֮�󣬽�ǧ���������Ѳ������˶����ˡ���", me, this);
		me->start_busy(2);
		return 1;
	}
	
	return CNpc::handle_action(comm, me, arg);
}

NPC_END;
