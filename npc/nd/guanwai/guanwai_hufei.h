// hufei.c
//sound 2001-07-18

NPC_BEGIN(CNguanwai_hufei);

virtual void create()
{
	set_name("����", "hu fei");
	set("gender", "����");
	set("nickname", "ѩɽ�ɺ�");
	set("age", 25);
	set("long", 
		"�����Ǻ���֮�ӣ������书��ǿ�����û���ڽ�����������š�ѩɽ�ɺ���������һ����ɫ�������������һ�ѿ������ܾɵĵ�����������ף�����������һͷŨ����ȴ����衣");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("icon",young_man2);	
	
	set("chat_chance", 20);	
	set("chat_chance_combat", 90);
        	
	set("hp", 3000);
	set("max_hp", 3000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 100);
	set("combat_exp", 890000);
	set("shen_type", 1);
	 
	set_skill("force", 210);             // �����ڹ�
	set_skill("hujia_daofa", 250);       // ���ҵ���	
	set_skill("blade", 220);             // ��������
	set_skill("hunyuan_yiqi", 220);      // ��Ԫһ����
	set_skill("dodge", 220);             // ��������
	set_skill("shaolin_shenfa", 220);    // ������
	set_skill("parry", 220);             // �����м�
		
	map_skill("force", "hunyuan_yiqi");
	map_skill("blade", "hujia_daofa");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "hujia_daofa");
        set_temp("apply/attack", 220);
        set_temp("apply/defense", 220);
        set_temp("apply/armor", 220);
        set_temp("apply/damage", 320);

	set_inquiry("�ּ�", "�ֻ���������ҷ�ɱ�������ɡ�");
	set_inquiry("������", "�ɶ��������������ҵ��������Ҵ�û��������");
	set_inquiry("������", "���˷���ͼҸ��������Ҹ�ȴ�������Ľ��¡�");
	set_inquiry("��С��", "��֪ʲôʱ�����ټ����������");
	set_inquiry("С��", "��֪ʲôʱ�����ټ����������");
	set_inquiry("С������", "��֪ʲôʱ�����ټ����������");
	set_inquiry("֣����", "������Ϊ�Ҷ����ġ�");
	set_inquiry("�԰�ˮ", "�������������? ");
	set_inquiry("������", "���ˣ��������������ˡ�");
//	set_inquiry("����",ask_me);
	/*
	set("inquiry",([
		"����":     (: ask_book :),
		"���ҵ���": (: ask_book :),
	]));

	set("baodao_count",1);
	set("book_count",1);
*/
	carry_object("gangdao")->wield();
	carry_object("cloth")->wear();
}

virtual char * chat_msg()				//NPC�Զ�����
{
	switch(random(3))
	{
	case 0:
		return 	"����̾�˿�����������֪ʲôʱ�����ټ���С�����";
	case 1:
		return 	"���ɺ޺޵���������������ɱ�����ˣ��ұر��˳𣡡�";
	case 2:
		return 	"�����гݺ޵������ּ����������¶����ұ����д�ⲣ���";
	}	
	return 0;
}
virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(3))
	{
	case 0:
		perform_action("blade huanying", 1);
		break;
	case 1:
		perform_action("blade lian", 1);
		break;
	case 2:
		perform_action("blade lian", 1);
		break;
	}	
	return 0;
}

/*

int accept_object(object me, object ob)
{
	int i;
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("��û�����������");
	if ( (string)ob->query("id") == "yan ji") 
	{
		write(HIC "\n���˵������λ" + RANK_D->query_respect(me)+"����˴����£�����ʵ��֪����Ϊ����\n");
		write(HIC "\n��쳴�ϲ�����������벻����Ҳ�н��죡�������䣬���ֻ���Ϊ���Ρ�\n"NOR);
                call_out("destroying", 1, this_object(), ob);
//		ob->die();
		me->set_temp("marks/hujiadaopu",1);
        }
	return 1;
}

string ask_book()
{
	object ob, me;
	
	me = this_player();
	if (!me->query_temp("marks/hujiadaopu",1)) return "��˵ʲô? \n";
	if((int)(me->query("shen")<100000))
		return "����������С֮�֣��������ֻ��ڶ���\n";

   	else 
	{
		if(query("book_count") > 0)
		{		
		write(HIC "���˵��ת����ֻ�ʬ�����ѳ�һ���ƾ��鱾�����˸��㡣\n");
	    		call_out("waiting",0,me,ob);
			add("book_count", -1);
    			ob = new ("/clone/book/blade_book");
    			ob->move(this_player());
			command("rumor "+me->query("name")+"�õ����ҵ�������\n");
			return "�Ȿ���ױ��⹷����ռ��ʱ�ˣ����ھ�������ɡ�\n";
		}
		else return "�������ˣ����ڵ����Ѳ��ڴ˴���\n";
	}

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}

static char * ask_me(CNpc *who,CChar *me)
{
	CContainer * obj;
	if( me->query("repute") < 0)
	{
		who->call_out(do_kill,1,me->object_id());
		return "";
	}

	if( me->query("repute") < 100000 )
	    return "����Ŀǰ����Ϊ�ǲ�������ѵ��ġ�";

   	if(me->query("baodao_count") > 1)
	{		
    //	call_out(waiting,0,me,ob->object_id());
		me->add("baodao_count", -1);
    	obj = load_item ("cwbdao");//��������
    	obj->move(me);
		return " �ðɣ���Ѵ��������������㣬ϣ����ú���������";
	}
	
	return "��������, ������ѵ��Ѳ��ڴ˴���";
}
*/
static void do_kill(CContainer *ob,LONG param1,LONG param2)
{
	CChar * npc = (CChar *)ob;
	CChar * me=(CChar *)(npc->environment())->Present(param1);
	if (!me) return;
 
    if ((me->environment())->query("no_fight"))
	    (me->environment())->set("no_fight", 0l);
 
    if (userp(me))
    {
        npc->say("����������Ҵ��ұ���������, ������������");
		npc->kill_ob(me);
    }
}

NPC_END;