//bj_hunaliangjin.h	��������
//�ز� 2003��6��5

NPC_BEGIN(CNbj_hunaliangjin);

void create()
{
	set_name("��������","hu na");
	set("long", "����������һ�ɣ�����ʮΧ�������ᣬ�����������ֳ����ٽ�˫������ս�������Ǳ����������䣬���屻�ٱ�����ʱ��������ɱ�����㣬�������أ�ҹ���կ��һ�ռ�����ʮ���ǣ�ʮ����׷�����ִ�Ԫ˧�����Ծ��������Բ���ɱ�Ͼ��ǡ������𶯣����а����������������¡�");
	set("title", "��·�ȷ��");
	set("gender", "����");
	set("age", 45);
	set("attitude", "peaceful");
	set("icon",general);
	set("per", 10);
	set("str", 41);
	set("int", 24);
	set("con", 38);
	set("dex", 32);
	set("no_kill",1);
	set_weight(50000000);

	set("max_hp", 15000);
	set("mp", 8000);
	set("max_mp", 8000);
	set("mp_factor", 160);

	set("combat_exp", 800000);
	set_skill("force", 250);
	set_skill("dodge", 250);
	set_skill("parry", 250);
	set_skill("axe",250);
	set_skill("unarmed", 250);
	set_skill("celestrike", 250);
	set_skill("tiexue_steps",250);
	set_skill("xiaowuxiang", 250);
	set_skill("duanyun_fu", 250);
  
	map_skill("force", "xiaowuxiang");
    map_skill("dodge", "tiexue_steps");
    map_skill("unarmed", "celestrike");
	map_skill("parry", "celestrike");
	map_skill("axe", "duanyun_fu");

	set("apply/armor", 300);
    set("apply/damage", 200);
	carry_object("axe");
	set("no_talk",1);
	set("no_huan",1);
};

int do_talk(CChar * me, char * ask = NULL)
{
	if(me->query_temp("zhang/����ǿ") && !me->query_temp("zhang/renwu6_1"))
	{
		if(me->query("level")<130)
		{
			char msg[255];
			say("ֻ��������������Ϳ�ع�����������ˣ�����˭�˵Ĳ��£���Ҫ��ĳ��Ӫ�����ߡ���ȥ��ȥ���߳���С�ľ������á���", me);
			say("������������ױ�����ͨ�����Ĳ��ɷ���һ�����ǡ�", me);
			me->set_temp("zhang/renwu6_1",1);
			CNpc * feng = load_npc("bj_fengziqiang");
			feng->set("owner",me->id(1));
			feng->move(load_room(snprintf(msg, 255,"������Ӫ��%d",random(4)+1)));
			SendMenu(me);
		}
		else
		{
			if(me->query("zhang/����1")&& me->query("zhang/����1")<3)
			{
				say("ֻ����������������ش��˸���Ƿ������˵���������ȥ�����ԣ�����ĳ����Ϊ���������޵У�û�ж��֣�ʮ�����ģ�Ҫ�������Ҹ����ֺ��Ҵ����ô������", me);
				say("����Ц����������Ը�����˾�񹦡���", me);
				say("��������б���۴��ϵ���Ƴ��Ƴ������Σ���Ц���ѣ�����������ģ�������ĳ��������ģ��������������˻�Ц�Һ�������Ű����ͯ�ģ��������������ö�˵�����Ƿ�ս�顣������Ҹ��൱�Ķ��֣���ʱ�����ٷ������Ӫ����", me);
				if(!me->query_temp("zhang/renwu6_2"))
				{
					load_item("zhanshu")->move(me);
					me->set_temp("zhang/renwu6_2",1);
				}
				SendMenu(me);
			}
			else
			{
				tell_object(me,"\n$HIR�������������ͭ����ľ��ֽ�����ס���ʵ��������֣���ϸ����");
				tell_object(me,"��ƤЦ�ⲻЦ�Ĵ��˸�������������ԭ�����ͽ��֣��һᡢ�һᣬֻ�ǽ���ʵ�ڲ��ң����»���Ҫ�������ټ����ټ�����");
				tell_object(me,"���������Ц���������ߣ��ѵ��д˶��֣����ܷŹ��㣬ֻҪ��Ӯ���ң����ȷ��Ӫ�������������\n");
				set("owner",me->id(1));
				me->set_temp("zhang/renwu6_4",1);
				CFightRoom * obj;
				CContainer * env = environment();
				obj = (CFightRoom *)load_item("fight_room");		
				
				obj->set("room_locked", FIGHT_NO_JOIN);
				obj->set_name( "���������ս��", "fight_room");		
				obj->move(env);
				me->move(obj);
				obj->Join_Team(me, CFightRoom::FIGHT_TEAM_B);
				this->move(obj);
				obj->Join_Team(this, CFightRoom::FIGHT_TEAM_A);
				obj->Begin_Fight(0);

				SendMenu(me);
			}
		}
		return 1;
	}
	return CNpc::do_talk(me,ask);
}

virtual int accept_object(CChar * me, CContainer * ob)
{
	if(!me->query_temp("zhang/renwu6_3") && me->query_temp("zhang/renwu6_1"))
		return 0;
	if(DIFFERSTR(ob->querystr("owner1"), me->id(1)))
		return 0;
	if(DIFFERSTR(ob->querystr("name"), "ս��") )
		return 0;
	if(!ob->query("use") )
		return 0;

	char msg[255];
	tell_object(me, "$HIR\n�������������˵��������Ҫս���Ǳ�ս--�á��á��ã�������������˸��ö��ְ���ĳ��Ҳ����ŵ����֮�ˣ����߰ɡ���\n");
	me->set_temp("zhang/renwu6_1",1);
	CNpc * feng = load_npc("bj_fengziqiang");
	feng->set("owner",me->id(1));
	feng->move(load_room(snprintf(msg, 255,"������Ӫ��%d",random(4)+1)));
	destruct(ob);
	return 1;
}

virtual void die()
{
	if(querystr("owner")[0])
	{
		CChar * me = (CChar *)find_object(query_temp("last_damage_from"), 1);
		if(me)
		{
			if(me->query_temp("zhang/renwu6_4")  && EQUALSTR(querystr("owner"), me->id(1)))
			{			
				char msg[255];
				tell_object(me, "�������������˵�������ù�����Ȼ���ǿ��书ʤ���Ҷ����ǿ�����������ĳ��˵���������������ǣ��ÿ�����");
				me->set_temp("zhang/renwu6_1",1);
				CNpc * feng = load_npc("bj_fengziqiang");
				feng->set("owner",me->id(1));
				feng->move(load_room(snprintf(msg, 255,"������Ӫ��%d",random(4)+1)));
				del("owner");
				set("hp",query("max_hp"));
				set("mp",query("max_mp"));
				set("eff_hp",query("max_hp"));
			}
		}
	}
	else
		CNpc::die();
}

NPC_END;




