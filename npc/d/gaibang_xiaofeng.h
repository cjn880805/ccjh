//xiaofeng.h
//code by zwb
//12-16

NPC_BEGIN(CNgaibang_xiaofeng);

virtual void create()
{
	set_name("����","xiao feng");

	set("gender", "����");
	set("nickname","���ƽ���");
	set("age", 28);
	set("long","������ؤ��ǰ�ΰ�������Ϊ�������Ѫͳ�������弫�˷����Ⱥ����¸���,����һ����ͨ�Ĵֲ����ӣ�������һ���������һϵ��������������࣬���ʮ�ֿ��࣬����һ�������ֿ���ʮ�����Ի������ӣ�˫Ŀ��磬��������");
	set("attitude", "peaceful");
 	set("icon",young_man6);
	
	set("str", 45);
	set("int", 30);
	set("con", 30);
	set("dex", 30);

	set("chat_chance", 1);

	set_inquiry("ؤ��","����������������");
	set_inquiry("��ʦ","�����ȥ�����ŵ��Ұ��ܶ��³������");

	set("hp", 4000);
	set("max_hp", 12000);
	set("mp", 4000);
	set("max_mp", 4000);
	set("mp_factor", 100);
	
	set("combat_exp", 180000);
	set("score", 20000);
	 
	set_skill("force", 120);             // �����ڹ�
	set_skill("huntian_qigong", 120);    // ��������
	set_skill("unarmed", 120);           // ����ȭ��
	set_skill("xianglong_zhang", 120);   // ����ʮ����
	set_skill("dodge", 120);      	     // ��������
	set_skill("xiaoyaoyou", 120);        // ��ң��
	set_skill("parry", 120);             // �����м�
	set_skill("begging", 50);            // �л�����
//	set_skill("checking", 50);           // ����;˵
	
	map_skill("force", "huntian_qigong");
	map_skill("unarmed", "xianglong_zhang");
	map_skill("dodge", "xiaoyaoyou");
	map_skill("parry", "xianglong_zhang");
	
	carry_object("cloth")->wear();
};

virtual char * chat_msg(CChar * player)
{
	switch(random(2))
	{
	case 0:
		return "�����̾�˿����������������벻������������ж�����Ȼ��ţ��������һ��Ů����ƭ��";
	case 1:
		return "������૵���������ؤ��ġ�����ʮ���ơ���������Ե����Ʒ�����";
	}
	return "";
}


virtual void init(CChar * player)
{
	if(userp(player))
	{
		remove_call_out(check_skills);
		call_out(check_skills, 2, player->object_id());
	}
}

static void check_skills(CContainer * npc , LONG param1 , LONG param2)
{
	CChar * player = (CChar *)(npc->environment())->Present(param1);
	
	if(! player) return;		//û����ҷ��ء�lanwood 2000-12-30

	CMapping * skl = player->query_skills();
	int counter,ob_shen;

	ob_shen=player->query("repute");

	counter=0;

	CVector v;

	skl->keys(v);
	for(int i=0; i<v.count(); i++)
	{
		if((*skl)[v[i]]>=100)
			counter++;
	}

	if(counter>=3)
	{
		if(!(npc->environment())->query("no_fight"))
			npc->call_out(do_kill,1,param1);
		return ;
	}
	else 
	{
		npc->call_out(waiting,0,param1);
		return ;
	}
	
}

static void do_kill(CContainer * ob ,LONG param1 , LONG param2)
{
	CChar * npc=(CChar *)ob;
	CChar * player=(CChar *)(npc->environment())->Present(param1);
	char msg[255];

	if(!player) return;

	if(player->query("yipin/joined"))
		return ;
	if(player && (npc->environment())->query("no_fight"))
	{
		message_vision(snprintf(msg,255,"$N��$n˵��������һ��һƷ�ø��־�������",query_rude(player)),npc,player);
		npc->kill_ob(player);
		player->fight_ob(npc);

		npc->call_out(checking,0,param1);
	}
	else
		npc->call_out(waiting,1,param1);

}

static void waiting(CContainer * ob , LONG param1 , LONG param2)
{
	CChar * npc=(CChar *)ob;
	CChar * player=(CChar *)(npc->environment())->Present(param1);

	if(player)
	{
		if(npc->is_fighting())
		{
			npc->call_out(checking,0,param1);
			return ;
		}
		else if(living(npc) && !(player->environment())->query("no_fight"))
			return ;
	}

	npc->remove_call_out(waiting);
	npc->call_out(waiting,20,param1);

}

static void checking(CContainer * ob ,LONG param1 , LONG param2)
{
	CChar * npc=(CChar *)ob;
	CChar * player=(CChar *)(npc->environment())->Present(param1);
	CContainer * corpse;

	if(! player) return;

	if(npc->is_fighting())
	{
		npc->call_out(checking,1,param1);
		return ;
	}

	corpse =(npc->environment())->PresentName("corpse_ob",IS_CORPSE);

	if(corpse && corpse->querystr("victim_name") == player->name())
	{
		npc->call_out(do_back,1,param1);
		return ;
	}

	npc->call_out(waiting,0,param1);
}

static void do_back(CContainer * npc , LONG param1 , LONG param2)
{
	CChar * player=(CChar *)(npc->environment())->Present(param1);

	if(!player) return;

	npc->move(load_room("/d/city/dongdajie2"));
	npc->set("combat_exp",1000000);
	message_vision("�������˹��������������ϵĳ�����΢΢һЦ˵�����ֳ���һ��������",player);
}



NPC_END;
