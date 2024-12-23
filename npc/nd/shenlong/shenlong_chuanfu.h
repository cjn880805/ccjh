// chuanfu.c �ϴ���
//code by sound
//2001-07-12

NPC_BEGIN(CNchuanfu);

virtual void create()
{
	set_name("�ϴ���", "lao chuanfu");
	set("gender", "����");
	set("age", 56);
 	set("icon",old_man2);
	set("long",
		"����һ���ϴ��򡣱�����˪������͸��һ˿�ƻ���������������\n"
		"��ǰ����ȥ����������������ӵ��һ�Ҵ󴬿��Գ�����\n");
	
	set("combat_exp", 1000000);
	set("shen_type", 1);
	
	set("max_hp",2000);
	set("hp",2000);
	set("max_mp", 1000);
	set("mp", 1000);
	set("mp_factor", 100);
	
	set_skill("force", 200);
	set_skill("unarmed", 400);
	set_skill("dodge", 200);
	set_skill("parry", 200);
	
	set_inquiry("���ߵ�", "���ߵ�����һ�����ˣ�ǧ����ȥ��");
	set_inquiry("������", "���ߵ�����һ�����ˣ�ǧ����ȥ��");
//	"����" :   (: chu_hai :),
	
	carry_object("cloth")->wear();
}
/*
int chu_hai()
{
	object ob, myenv ;
	ob = this_player ( ) ;
	if (ob->query("party/party_name") == $HIY "������" NOR)
	{
		message_vision("�ϴ���һ���֣������������ᴬ��\n",ob);
		message_vision("���ᴬ���$N���˴���һ������ê�����Ϳ����ˣ����ϴ���ȴû�ϴ�......\n", ob);
		myenv = environment (ob) ;
		ob->move ("/d/shenlong/dahai");
		tell_object(ob, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
		call_out("goto_shenlong",10,ob) ;
		return 1;
	}
	else  
		message_vision("�ϴ����������´�����$Nһ�£�ʲô���������㲻Ҫ���ˣ���\n"
		"�ϴ���������һ�£�����...�������һ�����ӣ�������Կ��ǡ�\n"
		,ob);
	ob->set_temp ("����" , 1 );
	return 1;
}

int accept_object(object who, object ob)
{
	object myenv ;
	if (!(int)who->query_temp("����"))
	{
		message_vision("�ϴ���Ц�Ŷ�$N˵���޹�����»���������Լ����Űɣ�\n", who);
		return 0 ;
	}
	if (ob->query("money_id") && ob->value() >= 10000) {
		message_vision("�ϴ����$N˵���ã���Ȼ��λ" + RANK_D->query_respect(who) +
			"��˿������ң�\n����Ҳƴ�������ƴ�����������ӱ��ˣ�\n" , who);
		this_player()->delete_temp("����" );
		message_vision("�ϴ���һ���֣������������ᴬ��\n", who);
		message_vision("���ᴬ���$N���˴���һ������ê�����Ϳ����ˣ����ϴ���ȴû�ϴ�......\n", who);
		myenv = environment (who) ;
		who->move ("/d/shenlong/dahai");
		tell_room(myenv,
			"�ϴ��򿴴����ˣ���������Ľ���Ц�ˣ�ȥ�������������������ҿɲ��ɡ�\n"
			"ֻ��ϧ���Ǽ��������Ĵ���Ҫ���ǰ��˸��Ե��ˡ��ٺ٣�������\n") ;
		tell_object(who, BLU "���ں��Ϻ����˺ܾúܾ�.......\n" NOR ) ;
		call_out("goto_shenlong",10,who) ;
		return 1;
	}
	else  
		message_vision("�ϴ�����ü��$N˵��������Ҳ̫���˰ɣ�\n", who);
	return 0;
}

void goto_shenlong (object ob)
{
	tell_object(ob , "������ͣ����һ��С���ߡ������´�����\n" ) ;
	ob->move ("/d/shenlong/haitan") ;
}
*/
NPC_END;