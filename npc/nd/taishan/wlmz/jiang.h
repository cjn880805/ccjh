//taishan_jiang.h
//code by sound
//2001-07-11

NPC_BEGIN(CNtaishan_jiang);

virtual void create()
{
	seteuid(getuid());

	set_name("����ʤ", "jiang baisheng");
	set("gender", "����" );
	set("age", 30);
	set("long", "������������κ��˫֮����֮�ױ��ӳ���\n");
	set("attitude", "heroism");
	set("generation",0);
	set("winner","none");

	set("str", 25);
	set("con", 25);
	set("int", 25);
	set("dex", 25);

	set("max_hp", 400);
	set("eff_qi", 400);
	set("qi", 400);
	set("hp", 200);
	set("jing", 200);
	set("mp", 300);
	set("max_mp", 300);
	set("mp_factor", 30);
	set("shen_type", 0);

	set("no_clean_up",1);
	set("combat_exp", 50000);

	set_skill("force", 80); 
	set_skill("unarmed", 100);
	set_skill("dodge", 80);
	set_skill("parry", 80);

	set("fight_times", 0);	
        
}

int accept_fight(object ob)
{
	object me  = this_object();
		
	me->set("eff_qi", me->query("max_hp"));
	me->set("qi",     me->query("max_hp"));
	me->set("jing",   me->query("hp"));
	me->set("mp",  me->query("max_mp"));

	if ( me->is_fighting()) return 0;

	if ( !present(ob, environment()) ) return 0;

	if ( me->query("fight_times") >= 10 )
		return notify_fail("����ʤ�Ѿ�ȫ��������ſ�ڵ��ϴ�ڵش��Ŵ�����\n");	

	me->add("fight_times", 1);

	remove_call_out("checking");
	call_out("checking", 1, me, ob);
	
	return 1;
}

int checking(object me, object ob)
{
	object obj;
	int my_max_hp, his_max_hp;

	if ( !present(ob, environment()) ) return 1; 

	my_max_hp  = me->query("max_hp");
	his_max_hp = ob->query("max_hp");

	if( me->is_fighting() ) 
	{
		if (( (int)me->query("qi")*100 / my_max_hp) <= 80 ) 
		{
			say(GRN "\n����ʤ˵���� κ���������£����ò����� �����˼������Ųߣ����޲��ˣ����޲�ʤ��\n" NOR);
			say(GRN "\n����ʤ˵���� κ����һ�仰�����°��´���������ֱǰ�� ����ѩ�����ﴳ����ɽ�𺣾͸�ȥ��\n" NOR);
			message_vision(HIY "\n����ʤ˵�꣬ȫ��֪������ð������һ����������������������ȭ��Ҳ���ͺö౶��\n" NOR, ob);

			me->set("eff_qi", me->query("max_hp"));
			me->set("qi",     me->query("max_hp"));
			me->set("jing",   me->query("hp"));
			me->set("mp",  me->query("max_mp"));
		}
		else if (( (int)ob->query("qi")*100 / his_max_hp) < 50 ) 
		{
			say(GRN "\n����ʤ˵���� ������С�Ӹ��һ�����һ����أ���ȥ����ʮ�������ɣ�\n");
			return 1;
		}

		if ( present(ob, environment()) ) call_out("checking", 1, me, ob);
	}

	return 1;  
}
