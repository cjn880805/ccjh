// yanziwu_azhu.c
//code by Fisho
//date:2000-12-22

NPC_BEGIN(CNyanziwu_azhu);

virtual void create()
{
	set_name("����", "azhu");
	set("long","���Ǹ������µ�Ů�ɣ���Լʮ�߰��꣬һ��������Ƥ�������� һ�Ŷ쵰���������鶯������һ�����˷��ϡ� ");
	
	set("gender", "Ů��");
	set("age", 17);
	set("icon",girl2);
	
	set("shen_type", 1);
	
	set("mp", 200);
	set("max_mp", 200);
	set("max_hp", 480);
	set_skill("force", 40);
	set_skill("unarmed", 40);
	set_skill("dodge", 30);
	set_skill("parry", 30);
	set_skill("sword", 30);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 10);
	set_temp("apply/damage", 5);
	
	set("combat_exp", 10000);
	
	carry_object("goldring")->wear();
	carry_object("necklace")->wear();
	carry_object("changjian")->wield();
	carry_object("pink_cloth")->wear();
	carry_object("flower_shoe")->wear();
	carry_object("mask");
	
	set_inquiry("����ɽׯ","�ҲŲ���ȥ����ɽׯ��������̫�Ե���! ");
	set_inquiry("������","����ֻ��������������ǹ��ӣ�Ҳ��֪��������ô����! ");
	set_inquiry("��ɺ", "��СѾͷҲ��ֻ���Ķ�ȥ�ˡ� ");
	set_inquiry("����", "���ɱ��˵�������ʵ�����ף�ֻҪ��ԭ�Ͼ����ˡ� ");
	set_inquiry("����" ,inquiry_tanqin);
	set("no_huan",1);
}

static char * inquiry_tanqin(CNpc *who,CChar *me)
{
	char msg[255];
	who->say(snprintf(msg,255,"����˵������λ%s��ô�����ˣ����Ҿ�Ϊ�㵯��һ������Ī������ֻ�����������������㲻�ɵĳ��ˡ� ",query_respect(me) ), me );
    who->say("ϸϸƷ�������������ܵ�<<���糱ˮ>>!!!  ",me);
    who->say("����һ�����ˣ������򸣣�˵�����ֳ��ˡ� ", me );
	who->SendMenu(me);
	return 0;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("wei/renwu5_4"))
	{
		if(! strlen(ask))
		{
			AddMenuItem("ѯ�ʹ�������֮��","yirong",me);
		}
		else if(!strcmp(ask, "yirong") )
		{
			me->set_temp("wei/renwu5_5",1);//��ʼѰ�����ݲ���
			say("���ɱ��˵����Ӻ����ף�ֻ�������û��ԭ���ˡ�",me);
			say("������ܰ���������̫���������Ƥ�����Ҿ��ܰ�������Ƥ����ˡ�",me);
		}
		SendMenu(me);
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(EQUALSTR(ob->querystr("name"), "����Ƥ") && ob->Query_Amount() ==5
		&& EQUALSTR(ob->querystr("id"), "bai yu pi")
		&& me->query_temp("wei/renwu5_5") && !me->query_temp("wei/renwu5_6"))
	{
		destruct(ob);
		char msg[255];
		tell_object(me,snprintf(msg,255,"\n$HIC����˵������%s�Ժ�Ƭ�̣���ȥȥ������\n",query_respect(me)));
		tell_object(me,"����ת�����˳�ȥ��\n");
		me->set_temp("wei/renwu5_6",1);//������5�Ű���Ƥ
		call_out(do_jiagong, 30);
		set("owner",me->id(1));
		move(load_room("temp_azhu"));
		return 1;
	}
	return 0;
}

static void do_jiagong(CContainer * ob, LONG param1, LONG param2)
{
	CChar * npc = (CChar *)ob;
	if(npc->querystr("owner")[0])
	{
		npc->move(load_room("�������ϼ��"));
		CContainer * me;
		CContainer * env=npc->environment();
		me=env->present(npc->querystr("owner"));
		if(me)
		{
			char msg[255];
			tell_object(me,"\n�������������˳�����");
			tell_object(me,snprintf(msg,255,"$HIC����˵������%s��ú��ˣ�������Ƥ��߾���%s�պá�\n",query_respect((CChar *)me),query_respect((CChar *)me)));
			me->set_temp("wei/renwu5_7",1);//�õ���Ƥ���
			load_item("killermask1")->move(me);
		}
		npc->del("owner");
	}
}
NPC_END;