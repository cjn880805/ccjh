// quanzhen_zhou.c �ܲ�ͨ

//code by Fisho
//date:2000-12-21

NPC_BEGIN(CNquanzhen_zhou);

virtual void create()
{
	set_name("�ܲ�ͨ", "zhou butong");
	set("gender", "����");
	set("nickname",  "����ͯ"  ) ;
	set("title", "ȫ��̵�һ������") ;
	set("age", 45);
	set("long","�������˳ơ�����ͯ�����ܲ�ͨ����������ȫ��������˵�ʦ�ܣ��书��ǿ��������ȴ������������ССɽ��֮�У�ͷ�����ӳ����ģ�ë���׵���һ��Ұ�ˡ�");
	
	set("combat_exp", 1000000);
	set("shen_type", 1);
	set("icon",old_man1);
	
	set("max_mp", 5000);
	set("mp", 5000);
	set("mp_factor", 0l);
			set("foolid",46);
	set_skill("force", 150);
	set_skill("sword", 100);
	set_skill("unarmed", 200);
	set_skill("dodge", 200);
	set_skill("parry", 100);
	set_skill("hubo" ,100);
	set_skill("kongming_quan",200);
	map_skill("unarmed","kongming_quan");
	
	create_family("ȫ���", 1, "����");
	set_temp("apply/attack", 50);
	set_temp("apply/defense", 50);
	set_temp("apply/damage", 15);
 	
	carry_object("cloth")->wear();

	set_inquiry("�����澭","�������澭�������Ҵ��ϣ����б���ɱ���һ���ұƳ�ɽ���Ϳ���ȡ�ߣ�");
	set_inquiry("���Ϲ�" ,"��������ʮ���꣬������ұƳ�ɽ����ȡ�������澭��������ÿ��������ɨ�˶��飡");
	set_inquiry("����","�ҡ��ҡ����Ҳ���ʶ����");
	set_inquiry("��","��Ҫ���ң����������ˣ�");
	set_inquiry("���",jie_bai);
	set("no_huan",1);
}

static char * jie_bai(CNpc *who,CChar *me)
{
	if ( DIFFERSTR(me->querystr("gender"), "����"))
		return "����ƽ��ϲͬ�����˴򽻵���һ��Ů�ˣ�����̫�ࡣ�ҿ��㻹�ǳ�����գ���";
			
	if ( me->query("repute") < -1000)
		return "����ͯ����һ��˵����ƾ�����ֶ���Ҳ�����ҳ��ֵ��ܣ���";

	who->say("�ã��Ժ����Ǿ��Ǻ��ֵ��ˣ�", me);
	who->say("�ϸ����һ�ס�˫�ֻ���֮������һ·������ȭ�����Դ�������Ϊ������Ӵ��", me);
	who->SendMenu(me);	

	me->set_temp("wantong/�ֵ�", 1);
	who->DownLoad(me);

	return 0;
}

virtual int prevent_learn(CChar * me, const char * arg)
{
	if(EQUALSTR(arg, "kongming_quan") || EQUALSTR(arg, "hubo"))
		return 0;

	return 1;
}

virtual int recognize_apprentice(CChar * ob)
{
	if (! ob->query_temp("wantong/�ֵ�"))
		return 0;
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if (EQUALSTR(ob->querystr("id"), "du she"))
	{
		message_vision("$N�ó�һ������������ͯ����ǰ���˻Σ���������������ͯ�ŵ�����������������⣡���ܱߺ������͸�ˣ�����ͯ�ⷬ�����ˣ���������Զȥ�����ڲ������š�" ,who);
		destruct(this);
		return 0;
	}
	return 0;
}
NPC_END;