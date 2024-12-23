// helian.c
//sound 2001-07-17

NPC_BEGIN(CNlingzhou_helian);

virtual void create()
{
	set_name("����ͭ��", "helian tieshu");
	set("title", "���Ĺ������󽫾�����һƷ���ܹ�");
	set("gender", "����");
	set("age", 35);
	set("str", 25);
	set("dex", 26);
	set("per", 16);
	set("icon",general);
	set("long", "���������ۣ���ʮ��������ͣ�ӥ���ǡ������롣");
	
	set("combat_exp", 500000);
	set("shen_type", -1);
	set("attitude", "peaceful");
	set("hp",2500);
	set("max_hp",2500);
	set("mp", 2500);
	set("max_mp", 2500);
	set("mp_factor", 200);
	
	set_skill("claw", 80);
	set_skill("force", 80);
	set_skill("parry", 80);
	set_skill("dodge", 40);
	set_skill("jiuyin_baiguzhao", 90);
	set_skill("bibo_shengong", 90);
	set_skill("lingxu_bu", 90);
	
	map_skill("force", "bibo_shengong");
	map_skill("parry", "luoying_shenjian");
	map_skill("dodge", "lingxu_bu");
	map_skill("claw", "jiuyin_baiguzhao");
	prepare_skill("claw", "jiuyin_baiguzhao");
	
	set_inquiry("һƷ��", "һƷ�þ���Ҫ����ԭ�������ԣ�");

	carry_object("jinduan")->wear();
}
/*
int accept_fight(object me)
{
	command("say �����һƷ����Ұ����Ҫ���ˣ�");
	return 0;
}

void init()
{
	add_action("give_quest", "quest");
}

int give_quest()
{
	mapping quest ;
	object me,ob;
	int j, combatexp, timep,factor,num;
	string tag = "2000000";
	string *levels = ({
		"10000",
			"15000",
			"20000",
			"30000",
			"50000",
			"80000",
			"100000",
			"130000",
			"170000",
			"220000",
			"300000",
			"450000",
			"600000",
			"800000",
			"1000000",
			"2000000"
	});
	me = this_player();
	combatexp = (int) (me->query("combat_exp"));
	if( !(int)me->query("yipin/joined"))
	{
		message_vision("����������$N����һ���������㲻�Ǳ��õİɣ������ʲô���֣���\n",me);
		return 1;
	}
	if(combatexp<10000)
	{
		message_vision("����������$N����һ������������С��ɫ����Ͷ��һƷ�ã���\n",me);
		return 1;
	}
	if(combatexp>800000)
	{
		message_vision("����������$N����һ�����������书̫���ˣ��Ѿ�û���ʺϸ���������ˡ���\n",me);
		return 1;
	}
	
//	Let's see if this player still carries an un-expired task
	if((quest =  me->query("quest")))
	{
		if( ((int) me->query("task_time")) >  time() )
		{
			message_vision("����������$N����һЦ����������������ˣ�\n", me);
			message_vision("���������ܲ�м�����$Nһ��˵������Ҫ��û���£����õ����
				�ó������ñ����ȥ��\n",me);
				return 0;
		}
		else
		{
			message_vision("������������$N̾��һ�����������Ҿ��ٸ���һ�λ���ɡ�\n", me);
			me->add("qi",-(int)(me->query("qi")/10));
		}
	}
	
	for(j= sizeof(levels) - 1 ; j>=0; j--)
	{
		if( atoi(levels[j])  <= combatexp )
		{
			num=j;
			factor=10;
			break;
		}
	}
	if (num>0)
	{
		if (random(50)>45)
		{
			num=num-1;
		}
	} 
	else
	{
		if ((num<sizeof(levels)-1)&&(random(100)>95))
		{
			num=num+1;
			factor=15;
		}
	}
	tag=levels[num];
	quest = QUESTH_D(tag)->query_quest();
	timep = quest["time"];
	
//	while (quest["quest_type"] == "ɱ")
//	{
//		quest = QUEST_D(tag)->query_quest();
//		timep = quest["time"];
//	}
	
	time_period(timep, me);
	if(quest["quest_type"]=="ɱ")
		tell_object(me,"���Ұѡ�"+quest["quest"]+HIW"������ɱ�ˣ���Ĳ�ʹ�Ժ���˵��\n" NOR);
	else
		tell_object(me,"�һء�"+quest["quest"]+HIW"�����ң���Ĳ�ʹ�Ժ���˵��\n" NOR);
	quest["exp_bonus"]=quest["exp_bonus"];
	quest["pot_bonus"]=quest["pot_bonus"];
	quest["score"]=quest["score"];
	
	me->set("quest", quest);
	if (ob = present("xin", this_player()))
	{
		destruct(ob);	 
	}
	me->set("task_time", (int) time()+(int) quest["time"]);
	me->set("quest_factor",factor);
	return 1;
}

int time_period(int timep, object me)
{
	int t, d, h, m, s;
	string time;
	t = timep;
	s = t % 60;			 t /= 60;
	m = t % 60;			 t /= 60;
	h = t % 24;			 t /= 24;
	d = t;
	
	if(d) time = chinese_number(d) + "��";
	else time = "";
	
	if(h) time += chinese_number(h) + "Сʱ";
	if(m) time += chinese_number(m) + "��";
	time += chinese_number(s) + "��";
	
	tell_object(me,HIW "���������Ը�����������" + time + "��");
	return 1;
}

int accept_object(object who, object ob)
{
	int bonus, exp, pot, score,factor;
	string test;
	mapping quest;
	
	if (ob->query("money_id"))
	{
		if(!who->query("quest"))
		{
			message_vision("��������Ц�������ҿɾͲ������ˡ�\n",who);
			return 1;
		}
//		if (who->query("songxin"))
//		{
//			message_vision("����һ�����ǽӵ�����������ô���������ȡ��������û�գ�\n",who);
//			return 1;
//		}
		else
			if ( ob->value() < 2000)
			{
				message_vision("��������һ˫�������۾�ֱ����$N�����Ǯ�ɲ������ǵĿ�����\n", who);
				return 1;
			}
			else
			{
				message_vision("��������Ц�����Ǻã������������������ڡ����ֲ�ʹ�����Ұɣ�\n",who);
				who->set("quest",0);
				return 1;
			}
	}
	
	if(!(quest =  who->query("quest")))
	{
		tell_object(who,"��������˵�����ⲻ������Ҫ�ġ�\n");
		return 0;
	}
	
	if( ob->query("name") != quest["quest"])
	{
		tell_object(who,"��������˵��������ʲô�������ҽ����Ĳ�ʹ���������Ū����\n");
		return 0;
	}
	
	if ((int) who->query("task_time") < time() )
	{
		tell_object(who,"��������˵�������Ƿ����û����ָ����ʱ���ڻ�����\n");
		destruct(ob);
		return 0;
	}
	else
	{
		tell_object(who,"������������ص�ͷ˵����������ʹ��û�����\n");
		exp = quest["exp_bonus"]/2 + random(quest["exp_bonus"]/2);
		pot = quest["pot_bonus"]/2 + random(quest["pot_bonus"]/2);
		score = quest["score"]/2 + random(quest["score"]/2);
		factor=who->query("quest_factor");
		destruct(ob);
		
		if (factor)
		{
			exp=exp*factor/10;
			pot=pot*factor/10;
			score=score*factor/10;
		}
		bonus = (int) who->query("combat_exp");
		bonus += exp;
		who->set("combat_exp", bonus);
		bonus = (int) who->query("potential");
		bonus = bonus - (int) who->query("learned_points");
		bonus = bonus + pot;
		if( bonus > 10000) bonus = 10000;
		bonus += (int) who->query("learned_points");
		who->set("potential", bonus );
		bonus = (int) who->query("score");
		bonus += score;
		who->set("score", bonus);
		tell_object(who,HIW"�㱻�����ˣ�" + chinese_number(exp)
			+ "��ʵս���飬"+ chinese_number(pot) + "��Ǳ�ܣ�"
			+ chinese_number(score)+"�㽭��������\n"NOR);
		who->set("quest", 0 );
		tell_object(who,HIW"��ϲ�����һ����ʹ��\n"NOR);
		return 0;
	}
	return 1;
}
*/

NPC_END;