// diyun.c
//sound 2001-07-18

NPC_BEGIN(CNguanwai_diyun);

virtual void create()
{
	set_name("����", "di yun");
	set("gender", "����");
	set("nickname", "���ǽ�");
	set("age", 25);
	set("long", 
		"�����ǵҺ��Ĵ���ӣ������书��ǿ�����û���ڽ�����������š����ǽ�����������ȥ����һ�����µ�ũ��");
	set("attitude", "peaceful");
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);
	set("per", 25);
	set("icon",young_man4);	
	
	set("chat_chance", 20);
	set("chat_chance_combat", 90);
	
	set("hp", 3000);
	set("max_hp", 3000);
	set("mp", 3000);
	set("max_mp", 3000);
	set("mp_factor", 100);
	set("combat_exp", 890000);
	set("score", 20000);
	
	set_skill("force", 110);             // �����ڹ�
	set_skill("doomsword", 250);		 // ���ǽ�
	set_skill("sword", 220);             // ��������
	set_skill("hunyuan_yiqi", 220);      // ��Ԫһ����
	set_skill("dodge", 120);             // ��������
	set_skill("shaolin_shenfa", 220);    // ������
	set_skill("parry", 220);             // �����м�
	
	map_skill("force", "hunyuan_yiqi");
	map_skill("sword", "doomsword");
	map_skill("dodge", "shaolin_shenfa");
	map_skill("parry", "hujia_daofa");
	set_temp("apply/attack", 120);
	set_temp("apply/defense", 120);
	set_temp("apply/armor", 120);
	set_temp("apply/damage", 520);
	
	set_inquiry("�����", "����ɽ��������ҷ�ɱ�������ɡ�");
	/*
	set("inquiry",([
	"����":     (: ask_book :),
	]));
	set("baodao_count",1);
	set("book_count",1);
	*/
	carry_object("gangjian")->wield();
	carry_object("cloth")->wear();
}

virtual char * chat_msg()				//NPC�Զ�����
{
	switch(random(3))
	{
	case 0:
		return 	"����̾�˿�����������֪ʲôʱ�����ټ���ʦ�á�";
	case 1:
		return 	"����޺޵��������������ɱʦ���ˣ��ұر��˳𣡡�";
	case 2:
		return 	"�����гݺ޵��������������¶��֣��ұ����д��ˣ���";
	}	
	return 0;
}

virtual char * chat_msg_combat()			//NPC�Զ�������
{
	switch(random(2))
	{
	case 0:
		perform_action("sword zhuang", 1);
		break;
	case 1:
		perform_action("force recover", 0);
		break;
	}	
	return 0;
}
/*
void do_kill(object ob)
{
	object me, room1;       
	me = this_object();
//	room1 = environment(me);
 
//	if (room1->query("no_fight"))
//	    room1->set("no_fight", 0);
 
	if (interactive(ob))
	{
		command("say ����������Ҵ��ҽ��׵����⣬������������\n");
		me->set_leader(ob);
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob);
	}
 
}	

int accept_object(object me, object ob)
{
	int i;
	if( !me || environment(me) != environment() ) return 0;
	if ( !objectp(ob) ) return 0; 
	if ( !present(ob, me) ) return notify_fail("��û�����������");
	if ( (string)ob->query("id") == "wanzhenshan") 
	{
		write(HIC "\n����˵������λ" + RANK_D->query_respect(me)+"����˴����£�����ʵ��֪����Ϊ����\n");
		write(HIC "\n���ƴ�ϲ�����������벻����Ҳ�н��죡�������䣬���ֻ���Ϊ���Ρ�\n"NOR);
                call_out("destroying", 1, this_object(), ob);
//		ob->die();
		me->set_temp("marks/lianchenpu",1);
        }
	return 1;
}

string ask_book()
{
	object ob, me;
	
	me = this_player();
	if (!me->query_temp("marks/lianchenpu",1)) return "��˵ʲô? \n";
	if((int)(me->query("shen")<100000))
		return "����������С֮�֣�����������ӵڶ���\n";

   	else 
	{
		if(query("book_count") > 0)
		{		
		write(HIC "����˵��ת��������ʬ�����ѳ�һ���ƾ��鱾�����˸��㡣\n");
	    		call_out("waiting",0,me,ob);
			add("book_count", -1);
    			ob = new ("/clone/book/lian_book");
    			ob->move(this_player());
			command("rumor "+me->query("name")+"�õ����ǽ�������\n");
			return "�Ȿ���ǽ��ױ��⹷����ռ��ʱ�ˣ����ھ�������ɡ�\n";
		}
		else return "�������ˣ��������ǽ����Ѳ��ڴ˴���\n";
	}

}

void destroying(object me, object obj)
{
        destruct(obj);
        return;
}
*/
NPC_END;