// wudang_shuanger.c

//code by Fisho
//date:2000-12-22
//inherit F_UNIQUE;

NPC_BEGIN(CNwudang_shuanger);

virtual void create()
{
	set_name("����",  "shuang er");
	set("title",  "������˫" );
	set("nickname",  "�󹦸��" );
	set("gender", "Ů��");
	set("age", 15);
        set("icon",girl2);

	set("attitude", "peaceful");
	set("shen_type", 1);
	set("str", 15);
	set("int", 25);
	set("con", 25);
	set("dex", 30);
	
	set("max_hp", 1500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_factor", 50);
	set("combat_exp", 50000+random(10000));
	set("score", 20000);
	
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("unarmed", 80);
	set_skill("sword", 80);
	set_skill("taiji_jian", 70);
	set_skill("taiji_quan", 70);
	set_skill("tiyunzong",50);
	map_skill("dodge", "tiyunzong");
	map_skill("parry", "taiji_jian");
	map_skill("sword", "taiji_jian");
	map_skill("unarmed", "taiji_quan");
	
	set_temp("apply/attack", 15);
	set_temp("apply/attack", 15);
	set_temp("apply/damage", 15);

	
	carry_object("changjian")->wield();
	carry_object("cloth")->wear();
	
}
/*
	set_inquiry("��Ը��Ը�������",ask_go);
	set_inquiry("�󹦸��",ask_kiss);
*/
/*
static char * ask_kiss(CNpc *who,CChar *me)
{
	char msg[255];
//	string host_id;

	if(querystr("id")!="shuang er")
	{
//		sscanf(query("id"),"%s's shuang er",host_id);
//		if(me->query("id")==host_id)
		if( ( me->query("id") ) == ( who->query("id") ))
		{
			if(random(10)<1)	          
			{
				who->say(snprintf(msg,255, "%s�����ߵ�ͨ��,����ͷ��,�����ĵ��˵�ͷ. ",query("name") ));
			}
			else 
				who->say(snprintf(msg,255,"%s����һ��,һ����������ȥ,˵:����,��Ҫ. ",query("name") ));
			return "";
		}
	}
	who->say(snprintf(msg,255,"%s˵��:��,�Ҳ���.",query("name") ));
	return "";
}

static char * ask_go(CNpc *who,CChar *me)
{
	char msg[255];
 	string new_name,new_id,host_id;
 	if(querystr("id")!="shuang er")
	{
//		sscanf(query("id"),"%s's shuang er",host_id);
		if(query("id")==host_id)
		{
			say(snprintf(msg,255,query("name")+"�����۾����˿�"+
				me->query("name")+"��˵:��ȻԸ����,�Ҷ�����ġ� ");
			return 1;
		}
		if(me->query("id")!=host_id)
		{
			say(snprintf(msg,255,query("name")+"�����۾����˿�"+
				me->query("name")+"��˵:���е�,�ҵ��������˵ġ� ");
			return 1;
		}
	}
	if (this_player()->query("weiwang")>=70)
	{
		write(  "������:���˴��Ҷ�����ɽ,���˶���ׯ�����д���� " );
		write(  "����Ҫ�ҷ�������,��һ�����ġ� " );
		command("nod");	
		set_leader(me);
		new_name = me->query("name")+"��Ѿ������";
		new_id=me->query("id")+"'s shuang er";
		set_name(new_name);
		set("id",new_id);
		write( "����ָ��: attack sb ����ĳ��. sha sb ɱ��ĳ��. stop ֹͣս��. sendto sb.--�Ѳ����͸�sb. ");
		set("long","����"+new_name+"�� "
			"����һ��ʮ���������Ů,��Լʮ���������; "
			"һ��ѩ�׵�����,ü����С,Ц���绨,��Ц�����ؿ����㡣 ");
	}
	else say(snprintf(msg,255,query("name")+"�����۾�����"+
		me->query("name")+"��˵:���е�,����û��ͬ�⡣ ");
	return 1;
}
*/
/*
int init()
{
	add_action("do_attack","attack");
	add_action("do_stop","stop");
	add_action("do_send","sendto");
	add_action("do_sha","sha");
}

virtual int handle_action(char *comm,CChar *me,char *arg)
{
	if (strcmp(comm,"attack") == 0)
		return do_attack();
	if (strcmp(comm,"stop") == 0)
		return do_stop();
	if (strcmp(comm,"sendto") == 0)
		return do_sendto();
	if (strcmp(comm,"sha") == 0)
		return do_sha();
	return 0;
}

int do_attack(string arg)
{
	object ob; 
	string host_id;
	object me=this_player();
	if(query("id")=="shuang er")
	{
		say("����Ȩʹ�ô���� ");
		return 0;
	}
	sscanf(query("id"),"%s's shuang er",host_id);
	if(me->query("id")!=host_id) return notify_fail("�������������㣡 ");
	if(!arg||!(ob=present(arg,environment(me))))
		return notify_fail("����ɵɵ�������㣬�����������˼�� ");
	if(!living(ob)) 
		return notify_fail("����˵:"
		+ob->query("name")+"�Ѿ��������㻹Ҫ...??!! ");
	if(ob->query("age")< 16 ) 
		return notify_fail("����˵:"
		+ob->query("name")+"���Ǹ�С����, ���˰�...!! ");
	if(!(ob->environment())->query("no_fight"))
	{
		message_vision("����������$N��ͷ��: ��,�õ�.. ",me);
		fight_ob(ob);
	}
	return 1;
}

int do_stop()
{
	string host_id;
	object me=this_player();
	if(query("id")=="shuang er") return notify_fail("����Ȩʹ�ô���� ");
	sscanf(query("id"),"%s's shuang er",host_id);
	if(me->query("id")!=host_id) return notify_fail("�������������㣡 ");
	if(!is_fighting()) return notify_fail("��������û���˴�.. ");
	command("halt");
	message_vision("����������$N΢΢һЦ�� ",me);
	return 1;
}

int do_send(string arg)
{
	object ob; string host_id,new_name,new_id;
	object me=this_player();
	if(query("id")=="shuang er") return notify_fail("����Ȩʹ�ô���� ");
	sscanf(query("id"),"%s's shuang er",host_id);
	if(me->query("id")!=host_id) return notify_fail("�������������㣡 ");
	if(!arg||!(ob=present(arg,environment(me))))
		return notify_fail("��Ҫ�Ѳ����͸�˭�� ");
	if(!living(ob)) 
		return notify_fail("��ֻ�ܰѲ���������! ");
	message_vision("����������������������$N��˵: ���˴��Һ�,��������;���˴��Ҳ���,�����������. ",me);
	set_leader(ob);
	new_name = ob->query("name")+"��Ѿ������";
	set("long","����"+new_name+"�� "
		"����һ��ʮ���������Ů,��Լʮ���������; "
		"һ��ѩ�׵�����,ü����С,ȴ���Ǹ������۸�,���������ؿ����㡣 ");
	new_id=ob->object_id()+"'s shuang er";
	set_name(new_name,new_id);
	write(  "������������"+ob->query("name")+"����������ӯӯһ�ݡ� " );
	message_vision("����ָ��: attack sb ����ĳ��. sha sb ɱ��ĳ��. stop ֹͣս��. sendto sb.--�Ѳ����͸�sb. ",me);
	return 1;
}

int do_sha(string arg)
{
	int i ;
	object me,ob;
	object* obj;
	me = this_object();
	if(!arg||!(ob=present(arg,environment(me))))
		return notify_fail("����˵: ������Ҫ����ɱ˭�� ");
	if(ob->query("age")< 16 ) 
		return notify_fail("����˵:"
		+ob->query("name")+"���Ǹ�С����, ���˰�...!! ");
	if(!(ob->environment())->query("no_fight"))
	{
		message_vision("������$N��ͷ˵��: ��, �õ�.  ",me);
		say(" ��, ����Ҫ��ɱ����! ");
		remove_call_out("kill_ob");
		call_out("kill_ob", 1, ob); 
	}
	return 1;
}       
*/
NPC_END;