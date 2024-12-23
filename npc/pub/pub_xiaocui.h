// pub_xiaocui.c

// code by Fisho
// date:2000-12-17

NPC_BEGIN(CNpub_xiaocui);

virtual void create()
{
	set_name("С��", "xiao cui");

	set("icon", taoistess);
	set("nickname", "�Ų��ͯ");
	set("gender", "Ů��" );
	set("age", 12+random(6));
	set("long","���Ǹ������䲻���С��������ɵĵ���Ҳ�ڲ�ס�����緢�������塣һ���������ɣ������������ݡ���������΢ʾ�⣬���ȥ�Ӳ赹ˮ��");
	set("attitude", "friendly");
	set("shen_type", 1);
	set("class", "taoist");
	
	set("str", 20);
	set("int", 28);
	set("con", 24);
	set("dex", 20);
	
	set("max_hp", 450);
	set("mp", 150);
	set("max_mp", 150);
	
	set("combat_exp", 1000+random(800));
	set("score", 1000);
	set("tea_count", 5);
	
	set_skill("force", 30);
	set_skill("dodge", 20);
	set_skill("unarmed", 15+random(10));
	set_skill("parry", 20);
	set_temp("apply/attack", 10);
	set_temp("apply/defense", 15);
	set_temp("apply/damage", 3);
	
	create_family("�䵱��", 5, "����");
	
	set_inquiry("Ů����","�⡸Ů���㡹���úܣ����δ����Ķ���Ҳ���������ţ��ο����㣿");

	carry_object("greenrobe")->wear();
	carry_object("necklace");
	set("no_huan",1);
}

virtual char * greeting(CChar * ob)
{
	char msg[255];
	say(snprintf(msg,255,"��λ%s��������������͸����ϲ衣",query_respect(ob) ));
	return "";
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * obn;
	char msg[255];
	
	if ( query("tea_count") < 1) return notify_fail("����ֻʣ������ˡ�");
	if ( EQUALSTR(ob->querystr("name"), "��Ҷ")  ||  EQUALSTR(ob->querystr("name"), "������" ) ) 
	{
		if ( EQUALSTR( ob->querystr("name"), "������" ) )
		{
			command(snprintf(msg,255,"kiss %ld" ,  who->object_id() )); 
			command(snprintf(msg, 255, "wield 0 %ld", ob->object_id()) );
		}
		
		if ( who->query_temp("marks/sit") )
		{
			if ( who->query_temp("tea_cup") > 0)	
			{
				command(snprintf(msg,255,"smile %ld", who->object_id() ));
			}
			else 
			{
				say(snprintf(msg,255,"С�����˸�Ҿ����%s���Ժ�СŮ����͸�������衣",query_respect(who) ), who);
			}
			
			who->set_temp("tea_cup", 5);
			remove_call_out(serve_tea);
			call_out(serve_tea, 1, who->object_id());
			
		} 
		else 
		{
			who->set_temp("tea_cup", 5);
			say(snprintf(msg,255,"С����˸��򸣣�%s������������СŮ����͸���ȥ����衣",query_respect(who) ), who);
		}

		SendMenu(who);
		return 1;
	}
	
	if ( EQUALSTR( ob->querystr("name"), "��Ů���㡹��Ҷ") )
	{
		if ( who->query_temp("marks/sit") )
		{
			who->command(snprintf(msg,255,"dance %ld" , who->object_id() ));
		} 
		else 
		{
			message_vision("С����$N�����߷羰��õ��������£�", who);
		}
		
		who->set_temp("tea_cup", 10);
		who->set_temp("marks/sit", 1);
		obn = load_item("nuerxiang");//Ů����
		obn->move(who);
		add("tea_count",-1);
		return 1;
	}

	who->command(snprintf(msg,255,"? " , who->object_id() ));
	return 1;
}


static void serve_tea(CContainer *ob,LONG param1,LONG param2)
{
	CContainer * obn;
	CChar * who = (CChar *)(ob->environment())->Present(param1);

	if(! who || !who->query_temp("marks/sit") ) return;
	
	if (  who->query_temp("tea_cup") <= 0 || who->query("tea_count") < 1 )
	{
		obn = load_item("dawancha");//�ִŴ���
		obn->move(who->environment());
		message_vision("С�������������������ϵĴ���赹����",who);
	} 
	else 
	{
		who->add_temp("tea_cup", -1);
		obn = load_item("xiangcha");//���
		who->add("tea_count",-1);
		obn->move(who->environment());
		message_vision("С���ó�������С��������˱���裬�������ϣ�",who);
	}
	
	obn = load_item("mitao");//ˮ����
	obn->move(who->environment());
	message_vision("С���ó�һ�����ʵ�ˮ���ң��������ϣ�", who);
	
	return;
}
NPC_END;