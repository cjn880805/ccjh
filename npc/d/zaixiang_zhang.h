//���׸�	�ز� 2002��5��23

CNpc * random_npc();

NPC_BEGIN(CNzaixiang_zhang);

void create()
{
	set_name("�ž���","zhang juzhong");
	set("long", "���ǳ�͢�ڸ��׸���Ȩ�㳯Ұ��Ϊ����Ȩı���е��ԡ������˲ţ��������Ǹ����\n");
	set("title", "�ڸ��׸�");
	set("gender", "����");
	set("age", 53);
	set("attitude", "peaceful");
	set("icon",41);
	set("per", 38);
	set("str", 500);
	set("dex", 500);
	set("hp", 500000);
	set("max_hp", 500000);
	set("combat_exp", 20000000);
	set_skill("force", 8000);
	set("task_open", 1);	//���񿪷�
	set("no_kill",1);
	set("no_talk",1);
	set("no_huan",1);
	
};

void init(CChar * me)
{
	CNpc::init(me);

	if(userp(me) && ! is_fighting())
	{
		remove_call_out(do_greeting);
		call_out(do_greeting, 3, me->object_id());
	}
}

static void do_greeting(CContainer * ob, LONG param1, LONG param2)
{
	CChar * me = (CChar *)ob;
	CChar * who = (CChar *)(me->environment())->Present(param1);

	if(! who) return;

    message_vision("$nЦ�ǺǶ�$N˵��:Ը���������°����", who, me);

	return;
}

int do_talk(CChar * me, char * ask = NULL)
{
	if(query("task_open"))
	{
		AddMenuItem("��Ҫ����", "$0askquest $1", me);
		AddMenuItem("���񱨸�", "$0report $1", me);
		AddMenuItem("�������", "$0fail $1", me);
		if(me->query("zhang/����")>10000 && me->query("zhang/����6")&& !me->query("zhang/����7"))
		{
			AddMenuItem("����洫����", "$0asw7 $1", me);
		}
		else if(me->query("zhang/����")>5000 && me->query("zhang/����5")&& !me->query("zhang/����6"))
		{
			if(!me->query("zhang/renwu6_end"))
				AddMenuItem("��ɱ����ָ��", "$0asw6 $1", me);
			else
				AddMenuItem("��ɱ����ָ������㱨", "$0asw6 $1", me);
		}
		else if(me->query("zhang/����")>2500 && me->query("zhang/����4")&& !me->query("zhang/����5"))
		{
			time_t t;	
			time(&t);
			if((t > me->query("zhang/renwu5_endtime")) && me->query("zhang/renwu5_endtime"))
				AddMenuItem("в����ʷ����㱨", "$0asw5 $1", me);
			else
				AddMenuItem("в����ʷë����", "$0asw5 $1", me);	
		}
		else if(me->query("zhang/����")>2000 && me->query("zhang/����3")&& !me->query("zhang/����4"))
			AddMenuItem("���ڵ���㱨", "$0asw4 $1", me);
		else if(me->query("zhang/����")>1500 && me->query("zhang/����2")&& !me->query("zhang/����3"))
			AddMenuItem("��ϥ��̸", "$0asw3 $1", me);
		else if(me->query("zhang/����")>1000 && me->query("zhang/����1") && !me->query("zhang/����2"))
			AddMenuItem("̸������", "$0asw2 $1", me);
		else if(me->query("zhang/����")>600 &&!me->query("zhang/����1"))
			AddMenuItem("Ͷ������", "$0asw1 $1", me);

		SendMenu(me);
		return 1;
	}
	else
	{
		say("�ţ��Ϸ���������ȥ�Ϸ���һ�⣬ֻ������ʱ��δ���������������հɣ�", me);
		SendMenu(me);
		return 1;
	}

	return CNpc::do_talk(me, ask);
}

int handle_action(char *comm, CChar *me, char * arg)
{
	if(query("task_open"))
	{
		if(strcmp(comm, "askquest") == 0)
			return do_aq(me);			
		if(strcmp(comm, "report") == 0)
			return do_r(me);
		if(strcmp(comm, "fail") == 0)
			return do_f(me);
		if(strcmp(comm, "asw1") == 0)
			return do_asw1(me);
		if(strcmp(comm, "asw11") == 0 && me->query("zhang/����")>600 &&!me->query("zhang/����"))
			return do_asw11(me);
		if(strcmp(comm, "asw12") == 0 && me->query("zhang/����")>600 &&!me->query("zhang/����"))
			return do_asw12(me);
		if(strcmp(comm, "asw13") == 0 && me->query("zhang/����")>600 &&!me->query("zhang/����"))
			return do_asw13(me);
		if(strcmp(comm, "asw14") == 0 && me->query("zhang/����")>600 &&!me->query("zhang/����"))
			return do_asw14(me);
		if(strcmp(comm, "asw2") == 0 && me->query("zhang/����1") &&!me->query("zhang/����"))
			return do_asw2(me);
		if(strcmp(comm, "asw21") == 0 && me->query("zhang/����1") &&!me->query("zhang/����"))
			return do_asw21(me);
		if(strcmp(comm, "asw22") == 0 && me->query("zhang/����1") &&!me->query("zhang/����"))
			return do_asw22(me);
		if(strcmp(comm, "asw23") == 0 && me->query("zhang/����1") &&!me->query("zhang/����"))
			return do_asw23(me);
		if(strcmp(comm, "asw24") == 0 && me->query("zhang/����1") &&!me->query("zhang/����"))
			return do_asw24(me);
		if(strcmp(comm, "asw3") == 0 && me->query("zhang/����2") &&!me->query("zhang/����"))
			return do_asw3(me);
		if(strcmp(comm, "asw31") == 0 && me->query("zhang/����2") &&!me->query("zhang/����"))
			return do_asw31(me);
		if(strcmp(comm, "asw32") == 0 && me->query("zhang/����2") &&!me->query("zhang/����"))
			return do_asw32(me);
		if(strcmp(comm, "asw33") == 0 && me->query("zhang/����2") &&!me->query("zhang/����"))
			return do_asw33(me);
		if(strcmp(comm, "asw34") == 0 && me->query("zhang/����2") &&!me->query("zhang/����"))
			return do_asw34(me);
		if(strcmp(comm, "asw4") == 0 && me->query("zhang/����3") &&!me->query("zhang/����"))
			return do_asw4(me);
		if(strcmp(comm, "asw5") == 0 && me->query("zhang/����4") &&!me->query("zhang/����"))
		{
			time_t t;	
			time(&t);
			if(me->query("zhang/renwu5_ok")||
				(t > me->query("zhang/renwu5_endtime")) && me->query("zhang/renwu5_endtime"))
				return do_asw5_ok(me);
			else
				return do_asw5(me);
		}
		if(strcmp(comm, "asw6") == 0 && me->query("zhang/����5") &&!me->query("zhang/����"))
		{
			if(!me->query("zhang/renwu6_end"))
				return do_asw6(me);
			else
				return do_asw6_ok(me);
		}
		if(strcmp(comm, "asw7") == 0 && me->query("zhang/����6") &&!me->query("zhang/����"))
		{
			return do_asw7(me);
		}
	}

	return CNpc::handle_action(comm, me, arg);
}

//����npc�ķ�λ
const char * position_npc(CChar * npc)
{
	CContainer * env = npc->environment();
	if(! env) return 0;	//ʧ��
	if(env->query("no_fight")) return 0;	//��ս������
	if(env->query("wiz_room")) return 0;	//��ʦ���䡣
	if(env->query("renwu")) return 0;		//�������񷿼䡣
	if(env->query("sleep_room")) return 0;	//��Ϣ����
	if(EQUALSTR(env->querystr("area"), "house")) return 0;	//���סլ
	if(EQUALSTR(env->querystr("area"), "Ұ��")) return 0;	//Ұ�ⳡ��
	if(EQUALSTR(env->querystr("id"), "fight_room")) return 0;	//ս������
	if(atoi(env->querystr("owner"))) return 0;	//���סլ

	while(env->environment())
		env = env->environment();

	return env->name(1);
}

int do_aq(CChar * me)
{
	char msg[255];
	
	static struct {
		char name[40];
		char desc[180];
		char basename[40];
	}monster[13] = {
		{"��ʷë����", "��ʷë�������׼�������������������ң���������취�������졣","yushi mao"},
		{"�ɶ��ᶽ", "�ɶ��ᶽ�ܾ�û�е���������˼��˼�ˣ�����ҳ��ʱ��ȥ�̽�������ô���µġ�","chengdu tidu"},
		{"ͨ��֪��", "ͨ��֪�ز�ʶ̧�٣��������洫���ǿ�������ҿ���������ã���֪������ôȥ���˰ɣ�","tongzhou zhixian"},
		{"��ѧʿ", "������һ��ѧʿ˽����ı�ᵳ����ͼ����ʥ�����Ϸ���ȥ�����˽���£�","daxue shi"},
		{"�½���ʷ", "�����糯����һ�½���ʷ���浯���Ϸ���������̫�����Ҳ�ϣ���ټ������ˡ�","xinjin yushi"},
		{"˾��̫��", "˾��̫�����Ƶ��˽�Գ����������Ѳ������δ��ˣ����ҽ������ܴ��������¾ͽ������ˡ�","sili taijian"},
		{"�ط�����ʹ", "ղ�¸��ܱ��еط�����ʹ˽������������ף�����Ұ�Ĳ�С���������������ϡ�","difang buzhoushi"},
		{"����֪��", "��ȷ����Ϣ������֪��˽�Կ���ͭ�󣬴���˶����ȥ�����͵�����������Ѻ��ؾ���","fuzhou zhifu"},
		{"����ָ��ʹ", "����ָ��ʹ�Ѷ��ҽ������ģ�����Ϊ������֮�ˣ���������Ϊ�У���Ӧ��֪�����ȥ���˰ɣ�","jinwei duzhihuei"},
		{"����ָ��", "���������ܱ�������ָ�ӽ�פ���߾�֮���������ر�����ͨ��������˹��Ҵ󻼣����ٰ�ɱ֮��","wang duzhihuei"},
		{"�ط�����ʹ", "�ط�����ʹһֱ������ε��������ԣ���Ϊ�ɶ���ɽ�֮��ȥ��","difang anchashi"},
		{"��ѧ����", "��һ��ѧ�����Գ���������ӡ��ʫʫ����������Ȼ��ϧ�������Ǳ����ȥ��","ruxue jiaoshou"},
		{"��������ָ��ʹ", "��������ָ��ʹ��Ϊ���������Ϸ򲻸����ţ�ȴ���ɲ��ţ���û��֤�����֣�ֻ�п��㰵ɱһ;�ˡ�","jinyi wei"},
	};
		LONG monster_id;

		if (me->query("combat_exp") < 10000)
			return notify_fail("���׸����������ˣ������������»�������Ϊ�á���");
		
		if (me->query_temp("zhang/finish"))
			return notify_fail("���׸�����Ŷ�����Ѿ����������Ϊ�β������Ҹ�֮��");
		
		if ( (monster_id = me->query_temp("zhang/doing")) )
		{
			//�ж������Ƿ�ʧ��
			CChar * mon = find_npc(monster_id);
			if(! mon)
				return notify_fail("���׸��ߵ�һ�����������ô������ѽ���������¶��첻�ɣ�");

			const char * area = position_npc(mon);
			if(! area) return notify_fail("���׸��ߵ�һ�����������ô������ѽ�����С�¶������ˣ�");

			int diff = me->query_temp("zhang/diff");
			tell_object(me, snprintf(msg, 255, "$HIW���׸�����%s���㻹����ȥ��", monster[diff].desc));
			return 1;
		}
		else if(me->query("zhang/renwu"))	//����ʧ
		{
			return notify_fail("���׸��ߵ�һ�����������ô������ѽ��");
		}
		
		if (me->is_busy())
			return notify_fail("�����ں�æ������");

	//���ȡһ��NPC�ĳ���	
	CNpc * npc = random_npc();

	if(! npc) return notify_fail("���׸������ţ��Ϸ���������ȥ�Ϸ���һ�⣬ֻ������ʱ��δ���������������հɣ�");
	if(npc == this) return notify_fail("���׸������ţ��Ϸ���������ȥ�Ϸ���һ�⣬ֻ������ʱ��δ���������������հɣ�");	//�Լ���Ȼ�������֡��Ǻǡ�
	if(! living(npc)) return notify_fail("���׸������ţ��Ϸ���������ȥ�Ϸ���һ�⣬ֻ������ʱ��δ���������������հɣ�");	//���NPC�첻���ˡ�
	if(DIFFERSTR(npc->querystr("race"), "����") ) return notify_fail("���׸������ţ��Ϸ���������ȥ�Ϸ���һ�⣬ֻ������ʱ��δ���������������հɣ�");	//������NPC
	if(npc->query("no_kill")) return notify_fail("���׸������ţ��Ϸ���������ȥ�Ϸ���һ�⣬ֻ������ʱ��δ���������������հɣ�");	//��һ����Ҳ������ҵ����������
	if(npc->query("mfnpc_lvl")) return notify_fail("���׸������ţ��Ϸ���������ȥ�Ϸ���һ�⣬ֻ������ʱ��δ���������������հɣ�");	//������ɽ���������
	
	CContainer * env = npc->environment();

	//�����ж�NPC���µķ�λ
	const char * area = position_npc(npc);
	if(! area ) return notify_fail("���׸������ţ��Ϸ���������ȥ�Ϸ���һ�⣬ֻ������ʱ��δ���������������հɣ�");	//���NPCû�л���
	if(! area[0]) return notify_fail("���׸������ţ��Ϸ���������ȥ�Ϸ���һ�⣬ֻ������ʱ��δ���������������հɣ�");	//���NPC����ҷ������ս���С�
	if(EQUALSTR(env->querystr("area"), "fight") ) return notify_fail("���׸������ţ��Ϸ���������ȥ�Ϸ���һ�⣬ֻ������ʱ��δ���������������հɣ�");	//���NPC����ҷ������ս���С�
	if(EQUALSTR(env->querystr("area"), "Ұ��") ) return notify_fail("���׸������ţ��Ϸ���������ȥ�Ϸ���һ�⣬ֻ������ʱ��δ���������������հɣ�");	//���NPC��Ұ�⡣
	if(env->query("renwu") ) return notify_fail("���׸������ţ��Ϸ���������ȥ�Ϸ���һ�⣬ֻ������ʱ��δ���������������հɣ�");	//���NPC����������ķ����С�

	int diff = random(13);
	npc = load_npc("pub_mafu");
	npc->set_name(snprintf(msg, 255, "%s%s",monster[diff].name,me->id(1)));
	npc->set("long","");
	npc->set("no_kill",1);
	npc->set("owner",me->id(1));
	npc->set("base_name",snprintf(msg, 255, "%s-%s",monster[diff].basename,me->id(1)));
	npc->set("id","chao guan");
	
	npc->set("str", me->query("str")+random(3));
	npc->set("int", me->query("int")+random(3));
	npc->set("con", me->query("con")+random(3));
	npc->set("dex", me->query("dex")+random(3));
	
	npc->set("max_hp",me->query("max_hp")*2);
	npc->set("eff_hp",me->query("max_hp")*2);
	npc->set("hp", me->query("max_hp")*2);
	npc->set("max_mp", me->query("max_mp"));
	npc->set("mp",  me->query("max_mp"));
	npc->set("mp_factor", me->query("mp_factor"));
	npc->set("combat_exp", int(me->query("combat_exp")/2));
	npc->set("level",me->query("level"));

	int i=me->query("level");
	if((me->query("level")<30 && me->query_skill("force", 1) < 110 && me->query_skill("dodge", 1) < 110 && me->query_skill("parry", 1) < 110)|| (me->query("level")>=30 && me->query("level")<60 && me->query_skill("force", 1) < 220 && me->query_skill("dodge", 1) < 220 && me->query_skill("parry", 1) < 220)|| (me->query("level")>=60 && me->query("level")<80 && me->query_skill("force", 1) < 285 && me->query_skill("dodge", 1) < 285 && me->query_skill("parry", 1) < 285) || me->query("level")>=80)
	{
		if(i>110)i=110;
	}
	else
		i=120;

	int lev=2;
	int leveldiff=int(i*lev);
	switch(random(15)+1)
	{
	case 1:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("taiji_shengong", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("tiyunzong", 50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("taiji_quan", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("taiji_jian", 50+leveldiff);
		npc->set_skill("blade", 50+leveldiff);
		npc->set_skill("taiji_dao", 50+leveldiff);
		npc->set_skill("taoism", 50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		
		npc->map_skill("force", "taiji_shengong");
		npc->map_skill("dodge", "tiyunzong");
		npc->map_skill("unarmed", "taiji_quan");
		npc->map_skill("parry", "taiji_jian");
		npc->map_skill("sword", "taiji_jian");
		npc->map_skill("blade", "taiji_dao");
		break;
	case 2:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("cuff", 50+leveldiff);
		npc->set_skill("strike", 50+leveldiff);
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("staff", 50+leveldiff);
		npc->set_skill("finger", 50+leveldiff);
		npc->set_skill("kurong_changong", 50+leveldiff);
		npc->set_skill("tiannan_step", 50+leveldiff);
		npc->set_skill("jinyu_quan", 50+leveldiff);
		npc->set_skill("wuluo_zhang", 50+leveldiff);
		npc->set_skill("duanjia_sword", 50+leveldiff);
		npc->set_skill("sun_finger", 50+leveldiff);
		npc->set_skill("lm_shangyang", 50+leveldiff);	
		npc->set_skill("literate", 50+leveldiff);
		
		npc->map_skill("force", "kurong_changong");
		npc->map_skill("dodge", "tiannan_step");
		npc->map_skill("finger", "sun_finger");
		npc->map_skill("cuff", "jinyu_quan");
		npc->map_skill("strike", "wuluo_zhang");
		npc->map_skill("parry", "sun_finger");
		npc->map_skill("sword", "duanjia_sword");
		npc->map_skill("staff", "duanjia_sword");
		
		npc->prepare_skill("cuff", "jinyu_quan");
		npc->prepare_skill("strike", "wuluo_zhang");
		break;
	case 3:
		npc->set_skill("persuading", 50+leveldiff);
		npc->set_skill("throwing", 50+leveldiff);
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("finger", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("strike", 50+leveldiff);
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("blade", 50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		npc->set_skill("mahayana", 50+leveldiff);
		npc->set_skill("buddhism", 50+leveldiff);
		npc->set_skill("jinding_zhang", 50+leveldiff);
		npc->set_skill("tiangang_zhi", 50+leveldiff);
		npc->set_skill("huifeng_jian", 50+leveldiff);
		npc->set_skill("yanxing_dao", 50+leveldiff);
		npc->set_skill("zhutian_bu", 50+leveldiff);
		npc->set_skill("linji_zhuang", 50+leveldiff);
		
		npc->map_skill("force","linji_zhuang");
		npc->map_skill("finger","tiangang_zhi");
		npc->map_skill("dodge","zhutian_bu");
		npc->map_skill("strike","jinding_zhang");
		npc->map_skill("sword","huifeng_jian");
		npc->map_skill("blade","yanxing_dao");
		npc->map_skill("parry","huifeng_jian");
		break;
	case 4:
		npc->set_skill("persuading", 50+leveldiff);
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("hand",50+leveldiff);
		npc->set_skill("staff", 50+leveldiff);
		npc->set_skill("hamagong", 50+leveldiff);
		npc->set_skill("chanchu_bufa", 50+leveldiff);
		npc->set_skill("shexing_diaoshou", 50+leveldiff);
		npc->set_skill("lingshe_zhangfa", 50+leveldiff);
		npc->set_skill("xunshou_shu",50+leveldiff);
		
		npc->map_skill("force", "hamagong");
		npc->map_skill("dodge", "chanchu_bufa");
		npc->map_skill("unarmed", "shexing_diaoshou");
		npc->map_skill("hand", "shexing_diaoshou");
		npc->map_skill("parry", "lingshe_zhangfa");
		npc->map_skill("staff", "lingshe_zhangfa");
		break;
	case 5:
		npc->set_skill("force", 50+leveldiff);           
		npc->set_skill("huntian_qigong", 50+leveldiff);    
		npc->set_skill("unarmed", 50+leveldiff);           
		npc->set_skill("xianglong_zhang", 50+leveldiff);   
		npc->set_skill("dodge", 50+leveldiff);      	     
		npc->set_skill("xiaoyaoyou", 50+leveldiff);      
		npc->set_skill("parry", 50+leveldiff);           
		npc->set_skill("staff", 50+leveldiff);            
		npc->set_skill("dagou_bang", 50+leveldiff);        
		npc->set_skill("begging", 50+leveldiff);           
		npc->set_skill("xunshou_shu", 50+leveldiff);
		
		npc->map_skill("force", "huntian_qigong");
		npc->map_skill("unarmed", "xianglong_zhang");
		npc->map_skill("dodge", "xiaoyaoyou");
		npc->map_skill("parry", "xianglong_zhang");
		npc->map_skill("staff", "dagou_bang");
		
		npc->prepare_skill("unarmed", "xianglong_zhang");
		break;
	case 6:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("yunv_xinfa", 50+leveldiff);	
		npc->set_skill("seaforce", 50+leveldiff);		
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("yunv_jian", 50+leveldiff);
		npc->set_skill("smithsword",50+leveldiff);	
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("xianyun_bufa", 50+leveldiff);	
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("meinv_quan", 50+leveldiff);    
		npc->set_skill("anranxiaohun_zhang", 50+leveldiff);
		npc->set_skill("tianluo_diwang", 50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		
		npc->map_skill("force", "seaforce");
		npc->map_skill("sword", "smithsword");
		npc->map_skill("dodge", "xianyun_bufa");
		npc->map_skill("parry", "anranxiaohun_zhang");
		npc->map_skill("unarmed", "anranxiaohun_zhang");
		break;
	case 7:
		npc->set_skill("cuff", 50+leveldiff);
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("strike",50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("zixia_shengong", 50+leveldiff);
		npc->set_skill("poyu_quan", 50+leveldiff);
		npc->set_skill("huashan_sword", 50+leveldiff);
		npc->set_skill("hunyuan_zhang", 50+leveldiff);
		npc->set_skill("lonely_sword", 50+leveldiff);
		npc->set_skill("huashan_shenfa",50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		npc->set_skill("zhengqijue", 50+leveldiff);
		
		npc->map_skill("cuff", "poyu_quan");
		npc->map_skill("force", "zixia_shengong");
		npc->map_skill("dodge", "huashan_shenfa");
		npc->map_skill("parry", "lonely_sword");
		npc->map_skill("sword", "lonely_sword");
		npc->map_skill("strike", "hunyuan_zhang");
		break;
	case 8:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("hand",50+leveldiff);
		npc->set_skill("strike", 50+leveldiff);
		npc->set_skill("sword",50+leveldiff);
		
		npc->set_skill("zhemei_shou",50+leveldiff);
		npc->set_skill("liuyang_zhang",50+leveldiff);
		npc->set_skill("tianyu_qijian",50+leveldiff);
		npc->set_skill("yueying_wubu",50+leveldiff);
		npc->set_skill("bahuang_gong", 50+leveldiff);
		
		npc->map_skill("force", "bahuang_gong");
		npc->map_skill("strike","liuyang_zhang");
		npc->map_skill("dodge", "yueying_wubu");
		npc->map_skill("unarmed", "liuyang_zhang");
		npc->map_skill("strike","liuyang_zhang");
		npc->map_skill("hand", "zhemei_shou");
		npc->map_skill("parry", "liuyang_zhang");
		npc->map_skill("sword","tianyu_qijian");
		
		npc->prepare_skill("strike","liuyang_zhang");
		npc->prepare_skill("hand","zhemei_shou");
		break;
	case 9:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("jiuyang_shengong", 50+leveldiff);
		npc->set_skill("lingfa", 50+leveldiff);
		npc->set_skill("shenghuo_lingfa", 50+leveldiff);
		npc->set_skill("qiankun_danuoyi", 50+leveldiff);
		npc->set_skill("shenghuo_xinfa", 50+leveldiff);
		
		npc->map_skill("parry", "qiankun_danuoyi");
		npc->map_skill("force", "jiuyang_shengong");
		npc->map_skill("dodge", "qiankun_danuoyi");
		npc->map_skill("lingfa", "shenghuo_lingfa");
		break;
	case 10:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("unarmed",50+leveldiff);
		npc->set_skill("strike",50+leveldiff);
		npc->set_skill("finger",50+leveldiff);
		npc->set_skill("literate",50+leveldiff);
		npc->set_skill("taoism",50+leveldiff);
		npc->set_skill("xiantian_qigong", 50+leveldiff);
		npc->set_skill("xiantian_gong", 50+leveldiff);
		npc->set_skill("quanzhen_jianfa",50+leveldiff);  
		npc->set_skill("quanzhen_jian",50+leveldiff);  
		npc->set_skill("jinyan_gong", 50+leveldiff);   
		npc->set_skill("haotian_zhang", 50+leveldiff);   
		npc->set_skill("sun_finger",50+leveldiff); 
		
		npc->map_skill("force", "xiantian_qigong");
		npc->map_skill("sword", "quanzhen_jianfa");
		npc->map_skill("dodge", "jinyan_gong");
		npc->map_skill("parry", "quanzhen_jianfa");
		npc->map_skill("strike", "haotian_zhang");
		npc->map_skill("finger","sun_finger");
		
		npc->prepare_skill("finger","sun_finger");
		npc->prepare_skill("strike","haotian_zhang");
		break;
	case 11:
		npc->set_skill("buddhism", 50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		npc->set_skill("blade", 50+leveldiff);
		npc->set_skill("claw", 50+leveldiff);
		npc->set_skill("club", 50+leveldiff);
		npc->set_skill("cuff", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("finger", 50+leveldiff);
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("hand", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("staff", 50+leveldiff);
		npc->set_skill("strike", 50+leveldiff);
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("whip", 50+leveldiff);
		
		npc->set_skill("banruo_zhang", 50+leveldiff);
		npc->set_skill("cibei_dao", 50+leveldiff);
		npc->set_skill("damo_jian", 50+leveldiff);
		npc->set_skill("fengyun_shou", 50+leveldiff);
		npc->set_skill("fumo_jian", 50+leveldiff);
		npc->set_skill("hunyuan_yiqi", 50+leveldiff);
		npc->set_skill("jingang_quan", 50+leveldiff);
		npc->set_skill("longzhua_gong", 50+leveldiff);
		npc->set_skill("luohan_quan", 50+leveldiff);
		npc->set_skill("nianhua_zhi", 50+leveldiff);
		npc->set_skill("pudu_zhang", 50+leveldiff);
		npc->set_skill("qianye_shou", 50+leveldiff);
		npc->set_skill("sanhua_zhang", 50+leveldiff);
		npc->set_skill("riyue_bian", 50+leveldiff);
		npc->set_skill("shaolin_shenfa", 50+leveldiff);
		npc->set_skill("weituo_gun", 50+leveldiff);
		npc->set_skill("wuchang_zhang", 50+leveldiff);
		npc->set_skill("xiuluo_dao", 50+leveldiff);
		npc->set_skill("yingzhua_gong", 50+leveldiff);
		npc->set_skill("yijinjing", 50+leveldiff);
		npc->set_skill("yizhi_chan", 50+leveldiff);
		npc->set_skill("zui_gun", 50+leveldiff);
		
		npc->map_skill("blade", "cibei_dao");
		npc->map_skill("claw", "longzhua_gong");
		npc->map_skill("club", "wuchang_zhang");
		npc->map_skill("cuff", "luohan_quan");
		npc->map_skill("dodge", "shaolin_shenfa");
		npc->map_skill("finger", "yizhi_chan");
		npc->map_skill("force", "yijinjing");
		npc->map_skill("hand", "fengyun_shou");
		npc->map_skill("parry", "nianhua_zhi");
		npc->map_skill("staff", "weituo_gun");
		npc->map_skill("strike", "banruo_zhang");
		npc->map_skill("sword", "fumo_jian");
		npc->map_skill("whip", "riyue_bian");
		
		npc->prepare_skill("finger", "yizhi_chan");
		npc->prepare_skill("strike", "banruo_zhang");
		break;
	case 12:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("strike", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("staff", 50+leveldiff);
		npc->set_skill("sword", 50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		
		npc->set_skill("shenlong_xinfa", 50+leveldiff);
		npc->set_skill("yixingbu", 50+leveldiff);
		npc->set_skill("shenlong_bashi", 50+leveldiff);
		npc->set_skill("huagu_mianzhang", 50+leveldiff);
		npc->set_skill("shedao_qigong", 50+leveldiff);
		
		npc->map_skill("force", "shenlong_xinfa");
		npc->map_skill("dodge", "yixingbu");
		npc->map_skill("unarmed", "shenlong_bashi");
		npc->map_skill("strike", "huagu_mianzhang");
		npc->map_skill("parry", "shedao_qigong");
		npc->map_skill("sword", "shedao_qigong");
		
		npc->prepare_skill("strike", "huagu_mianzhang");
		npc->prepare_skill("unarmed", "shenlong_bashi");
		break;
	case 13:
		npc->set_skill("force", 50+leveldiff);            
		npc->set_skill("claw", 50+leveldiff);              
		npc->set_skill("hand", 50+leveldiff);            
		npc->set_skill("finger", 50+leveldiff);          
		npc->set_skill("unarmed", 50+leveldiff);         
		npc->set_skill("strike", 50+leveldiff);          
		npc->set_skill("leg",50+leveldiff);	           
		npc->set_skill("dodge", 50+leveldiff);           
		npc->set_skill("parry", 50+leveldiff);            
		npc->set_skill("sword", 50+leveldiff);           
		
		npc->set_skill("anying_fuxiang", 50+leveldiff);    
		npc->set_skill("tanzhi_shentong", 50+leveldiff);   
		npc->set_skill("xuanfeng_leg", 50+leveldiff);      
		npc->set_skill("luoying_shenzhang", 50+leveldiff);     
		npc->set_skill("bibo_shengong", 50+leveldiff);     
		npc->set_skill("luoying_shenjian", 50+leveldiff);  
		npc->set_skill("yuxiao_jianfa", 50+leveldiff);       
		npc->set_skill("lanhua_shou", 50+leveldiff);       
		npc->set_skill("qimen_wuxing",50+leveldiff);       
		npc->set_skill("literate", 50+leveldiff);           
		
		npc->map_skill("force"  , "bibo_shengong");
		npc->map_skill("finger" , "tanzhi_shentong");
		npc->map_skill("hand"   , "lanhua_shou");
		npc->map_skill("unarmed", "luoying_shenzhang");
		npc->map_skill("strike", "luoying_shenzhang");
		npc->map_skill("leg", "xuanfeng_leg");
		npc->map_skill("dodge"  , "anying_fuxiang");
		npc->map_skill("parry"  , "tanzhi_shentong");
		npc->map_skill("sword"  , "tanzhi_shentong");
		
		npc->prepare_skill("finger", "tanzhi_shentong");
		npc->prepare_skill("hand", "lanhua_shou");
		break;
	case 14:
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("beiming_shengong", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("lingboweibu", 50+leveldiff);
		npc->set_skill("unarmed", 50+leveldiff);
		npc->set_skill("liuyang_zhang", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("blade", 50+leveldiff);
		npc->set_skill("xiaoyao_dao", 50+leveldiff);
		npc->set_skill("zhemei_shou", 50+leveldiff);
		npc->set_skill("hand", 50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		
		npc->map_skill("force", "beiming_shengong");
		npc->map_skill("dodge", "lingboweibu");      
		npc->map_skill("hand", "zhemei_shou");
		npc->map_skill("unarmed", "liuyang_zhang");
		npc->map_skill("parry", "xiaoyao_dao");
		npc->map_skill("blade", "xiaoyao_dao");
		
		npc->prepare_skill("hand","zhemei_shou");
		npc->prepare_skill("unarmed","liuyang_zhang");
		break;
	case 15:
		npc->set_skill("throwing", 50+leveldiff);
		npc->set_skill("feixing_shu", 50+leveldiff);        
		npc->set_skill("force", 50+leveldiff);
		npc->set_skill("huagong_dafa", 50+leveldiff);
		npc->set_skill("dodge", 50+leveldiff);
		npc->set_skill("zhaixinggong", 50+leveldiff);
		npc->set_skill("strike",50+leveldiff);
		npc->set_skill("xingxiu_duzhang", 50+leveldiff);
		npc->set_skill("parry", 50+leveldiff);
		npc->set_skill("staff", 50+leveldiff);
		npc->set_skill("tianshan_zhang", 50+leveldiff);
		npc->set_skill("literate", 50+leveldiff);
		npc->set_skill("sanyin_wugongzhao", 50+leveldiff);
		npc->set_skill("claw", 50+leveldiff);
		npc->set_skill("poison", 50+leveldiff);
		
		npc->map_skill("force", "huagong_dafa");
		npc->map_skill("dodge", "zhaixinggong");
		npc->map_skill("strike", "xingxiu_duzhang");
		npc->map_skill("parry", "feixing_shu");
		npc->map_skill("staff", "tianshan_zhang");
		npc->map_skill("unarmed", "xingxiu_duzhang");
		npc->map_skill("claw", "sanyin_wugongzhao");
		
		npc->prepare_skill("unarmed", "xingxiu_duzhang");
		npc->prepare_skill("claw", "sanyin_wugongzhao");
		break;	
	}
	npc->move(load_room(env->querystr("base_name")));

	me->set_temp("zhang/doing", npc->object_id());
	me->set_temp("zhang/diff", diff);			//�Ѷ�ϵ��
	me->set_temp("zhang/name", npc->querystr("name"));	

	me->set("zhang/renwu", 1);	//�ӹ������ˡ�
		
	message_vision(snprintf(msg, 255, "$HIW���׸���%s˵����%s������������⣬��Ӧ����%s�ش���", me->name(),  monster[diff].desc,env->querystr("area")), me);

	g_Channel.do_channel(&g_Channel, NULL, "sys", 
		snprintf(msg, 255, "%s��ɱ%s��%s������", me->name(1), env->querystr("base_name"), npc->name(1)));
		
	return 1;

}

int do_f(CChar * me)
{
	
	if(! me->query("zhang/renwu"))
		return notify_fail("���׸���ü�����������ȥ�������");

	if (me->query_temp("zhang/finish"))
			return notify_fail("���׸�����Ŷ�����Ѿ����������Ϊ�β������Ҹ�֮��");
	
	message_vision("$HIY���׸���ʱ������Ц������̾����������$N���ǲ������á���\n�ž��ж�������ζ��½���5�㡣", me);
	
	me->receive_wound("hp", me->query("max_hp") / 3, this);
	me->receive_damage("hp", me->query("max_hp") / 2, this);
	me->add("zhang/����",-5);
	if(me->query("zhang/����")<0)
		me->del("zhang/����");
	me->SendState(me);
	
	me->delete_temp("zhang");
	if(me->query("zhang/count")>10)
		me->add_temp("zhang/count",-10);
	else
		me->delete_temp("zhang/count");
	me->del("zhang/renwu");
	return 1;
}


//������
void reward_exp(CChar * me)
{
	char msg[255], tmp[40];
	LONG exp = me->query("level");		

	exp = exp * 2;
	
	//exp = exp * (10 + me->query_temp("fool/diff")) / 10;	//�Ѷ�ϵ��
	exp = exp + random(me->query("level"));	//�Ѷ�ϵ��

	exp = (random(exp) + exp) / 2;
	exp=exp*(1+me->query_temp("zhang/count")/10);
	if(exp>800)
		exp=random(400)+400;
	me->add_temp("zhang/count",1);
	if(me->query_temp("zhang/count")>60)
		me->set_temp("zhang/count",1);

	me->add("combat_exp", exp);
	me->add("zhang/����",1);
	int repute=int((random(31)+100)*(10+me->query_temp("zhang/count"))/10);
	me->add("repute",-repute);
	tell_object(me, snprintf(msg, 255, "$HIC������%s�㾭�顢%d�㽭��������\n�ž��ж�������ζ�������1�㡣", chinese_number(exp, tmp),-repute));

	g_Channel.do_channel(&g_Channel, 0, "sys", 
		snprintf(msg, 255, "%s�����ɱ%s�����񣬻��%d���顢%d�㽭��������", me->name(1), me->querystr_temp("zhang/name"),  exp,-repute));

	me->FlushMyInfo();
}

int do_r(CChar * me)
{
	if(! me->query("zhang/renwu"))
		return notify_fail("���׸���ü�����������ȥ�������");

	if (!me->query_temp("zhang/finish"))
		return notify_fail("���׸���ü������ɱ��������ô�ҽ����糯·�ϻ�����˵������Ļ�������");
		
	message_vision("$HIG���׸�����Ц�����ã��ã��ã�$N�����°�Ĳ�����ȥ��Ϣ�ɣ�",me);
	
	reward_exp(me);
	
	me->delete_temp("zhang/finish");
	me->delete_temp("zhang/diff");
	me->delete_temp("zhang/name");
	me->delete_temp("zhang/doing");
	me->del("zhang/renwu");
	me->start_busy(6);
	return 1;
}


int do_asw1(CChar * me)
{
	say("���׸�Ц��������������ģ�Ͷ���ҵ�������������Ҳδ�����ɡ�",  me);
	say("�ҵİ����ϰ��������飬���ҳ���֮����㿴��������������ϲ������ʲô�أ���",  me);
	AddMenuItem("���׾���", "$0asw11 $1", me);//����
	AddMenuItem("������ͨ����", "$0asw12 $1", me);//�Ĺ�
	AddMenuItem("��ʯͷ�ǡ�", "$0asw13 $1", me);//ѧʿ
	AddMenuItem("ֻϲ�������书�ؼ�", "$0asw14 $1", me);//�佫

	SendMenu(me);
	return 1;
}

int do_asw11(CChar * me)
{
	say("�ž�����ɫһ�䣬�����������Ȼѧ�����ˣ���ء����ء�������䡷��������������������һ��ͨ��һ������",  me);
	say("�����⼸���Ϲ�����������������",  me);
	say("�ֽ��ƺ�ֻ�С����ء��еġ��׾������Դ��������֪�δ����й����ű����ɷ�����Ϸ�һ�ۣ���",  me);
	SendMenu(me);
	me->set("zhang/�׾�",1);
	return 1;
}

int do_asw12(CChar * me)
{
	say("�ž��и��׳�Ц���۽�����ƺ��ѿ�͸�����Ǹ�ע����ʵ���ˣ������㱻���õĲ�������֮ʱ�����ǳ���������ɤ��˵����",  me);
	say("�����Ȼ�������ˣ������ơ��벿���������¡����Ϸ�ȴ��Ϊ�ǡ��벿ͨ�������¡����������Ϸ�֪������",  me);
	say("�㲻�ɵ�����������ǳ�ݣ����ǿ־壬ӦҲ���ǣ���Ҳ���ǣ�ֻ��ΨΨŵŵ������ȥ����",  me);
	SendMenu(me);
	me->set("zhang/����1",2);
	if(me->query_temp("zhang/�׾�"))me->delete_temp("zhang/�׾�");
	return 1;
}

int do_asw13(CChar * me)
{
	say("�ž��и����ⲽ�����쳤̾�������������������ˣ������⾩����Ȼ�˿̷��Ƽʻᡢ�����Ի���������־ʿ��ȴ��һ���������ӵ���׶֮�أ������ǿ����˾������ƣ����������ɡ���",  me);
	say("˵����������ļ磬��ͻȻ�е�һ���縸�װ����ů���ֺ�Ȼ��������Զ���ļ��ˣ���ͷһ�������������",  me);
	SendMenu(me);
	if(me->query_temp("zhang/�׾�"))me->delete_temp("zhang/�׾�");
	return 1;
}

int do_asw14(CChar * me)
{
	say("�ž��а��׹�����Ц��������˵�������Ȼ��һ�����䣬������ģ��Ϸ�����Ľ�ľ��������ֺ�ˬ���ڡ�ֻҪ���һ�����տ�Ϊ�Ϸ����ã��ٻ�������֮��������",  me);
	SendMenu(me);
	me->set("zhang/����1",4);
	if(me->query_temp("zhang/�׾�"))me->delete_temp("zhang/�׾�");
	return 1;
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	if(!who->query("zhang/�׾�"))	return 0;
	if(DIFFERSTR(ob->querystr("name"), "�����ԡ�") && DIFFERSTR(ob->querystr("name"), "����ͼ��") )	return 0;
	destruct(ob);
	say("�ž��о�������������ҵ���������ű�����������͸��Ϸ�", who);
	who->set("zhang/����1",1);
	say("�ž��ж�������ζ�������40�㡣",who);
	say("������50000����Ǯ��������10000��Ĺٳ����顣",who);
	who->add("zhang/����",150);
	who->add("combat_exp",10000);
	CMoney::Pay_Player(who, 50000);
	who->delete_temp("zhang/�׾�");
	SendMenu(who);
	return 1;
}

int do_asw2(CChar * me)
{
	say("ֻ���ž�������˫�ۣ�ճ���ʵ�������Ȼ˵�����ˣ����������к����",  me);
	AddMenuItem("��������������", "$0asw21 $1", me);
	AddMenuItem("�������лƽ���", "$0asw22 $1", me);
	AddMenuItem("��������ǧ����", "$0asw23 $1", me);
	AddMenuItem("�������о�����", "$0asw24 $1", me);
	SendMenu(me);
	return 1;
}

int do_asw21(CChar * me)
{
	if(DIFFERSTR(me->querystr("class"), "bonze") )
	{
		say("�ž��и��׳�Ц����Ŷ�������������ģ����Ϸ�����ʱ���һ��������������������",  me);
		if(me->querymap("couple"))
		{
			CUser * targetx;
			char idd[255];
			snprintf(idd,255,"%s",me->querystr("couple/id"));
			targetx=find_online(idd);
			if (targetx)
			{
				if(DIFFERSTR(me->querystr("gender"), "Ů��"))
				{
					say("$HIR�����ӵ�����������1��",me);
					if(targetx->query("per")<38)
						(CChar *)targetx->add("per",1);
				}
				else if(DIFFERSTR(me->querystr("gender"), "����"))
				{
					say("$HIR���ɷ������������1��",me);
					if(targetx->query("per")<38)
						(CChar *)targetx->add("per",1);
				}
			}
			else
			{
				targetx = add_user();
				targetx->set("id", me->querystr("couple/id"));
				targetx->LoadFromServer();
				
				if(DIFFERSTR(me->querystr("gender"), "Ů��"))
				{
					say("$HIR�����ӵ�����������1��",me);
					if(targetx->query("per")<38)
						(CChar *)targetx->add("per",1);
				}
				else if(DIFFERSTR(me->querystr("gender"), "����"))
				{
					say("$HIR���ɷ������������1��",me);
					if(targetx->query("per")<38)
						(CChar *)targetx->add("per",1);
				}
				targetx->Save();
			}
			
		}
		else if(EQUALSTR(me->querystr("class"), "bonze"))
		{
			say("�ž�����ü��������ô�����ں쳾��,�������⸶��Ƥ��ô����",  me);
			say("$HIR��������½���3��",me);
			me->add("per",-3);
			me->set("zhang/��������",3);
			if(me->query("per")>1)
				me->set("per",1);
		}
	}
	SendMenu(me);
	me->set("zhang/����2",1);
	return 1;
}

int do_asw22(CChar * me)
{
	say("�ž��г�˼����������ţ���������Ȱѧ���д�һ˵Ҳ����ֱ���ˡ��ʵ۰���Ҳ̫�����������������ˡ�����Ӧ��ϸ���á�",  me);
	SendMenu(me);
	me->set("zhang/����2",2);
	return 1;
}

int do_asw23(CChar * me)
{
	say("�ž��и��׳�Ц�����������ǵ��ǡ�ǧ���ڡ�����ı�Կ��������󵽡���",  me);
	SendMenu(me);
	me->set("zhang/����2",3);
	return 1;
}

int do_asw24(CChar * me)
{
	say("�ž��и��׳�Ц��˵������������գ�����һ�仰���벻���书�����������������������������κ�ڡ���",  me);
	SendMenu(me);
	me->set("zhang/����2",4);
	return 1;
}

int do_asw3(CChar * me)
{
	if(!me->query("zhang/����3"))
	{
		say("�ž��з�����ļ磬���˻�������,ֻ���������ĳ���˵��������������,�Ϸ򵽵����?��",  me);
		AddMenuItem("�Ŵ���ʵ��������֮�䷶", "$0asw31 $1", me);
		AddMenuItem("�Ŵ���λ��Ȩ������������������", "$0asw32 $1", me);
		AddMenuItem("......", "$0asw33 $1", me);
		AddMenuItem("�Ŵ��˶Ե�������ƺ�̫��������", "$0asw34 $1", me);
	}
	else
	{
		switch(me->query("zhang/����3"))
		{
		case 1:
			say("�ž�����ɫ����˵����������ˣ�����Ȱ��Ϸ��һ�����¡����³�֮���Ϸ�ض����á�����㣡",me);
			say("�ݱ������������ھ�����ٶ��쳣���������Ͳ����ڻ������ӣ��㻯װ����ʦȥ��̽��̽���Ǳ�����ʲô�ڣ�",me);
			say("���¹�ϵ�ҳ����ӣ��������С�ģ�����й©���٣��ǵó��������һ㱨��",me);
			break;
		case 2:
			say("�ž�����ɫ����˵����������ˣ�����Ȱ��Ϸ��һ�����¡����³�֮���Ϸ�ض����������мӣ�",me);
			say("�ݱ������������ھ�����ٶ��쳣���������Ͳ����ڻ������ӣ��㻯װ����ʦȥ��̽��̽���Ǳ�����ʲô�ڣ�",me);
			say("���¹�ϵ�ҳ����ӣ��������С�ģ�����й©���٣��ǵó��������һ㱨��",me);
			break;
		case 3:
			say("�ž����������˵�������ƺ��п����԰����Ϸ�Ҳ�Ͳ���ǿ�ˡ�����Ȱ��Ϸ��һ�����°ɣ�",me);
			say("�ݱ������������ھ�����ٶ��쳣���������Ͳ����ڻ������ӣ��㻯װ����ʦȥ��̽��̽���Ǳ�����ʲô�ڣ�",me);
			say("���¹�ϵ�ҳ����ӣ��������С�ģ�����й©���٣��ǵó��������һ㱨��",me);
			break;
		case 4:
			say("�ž��г�˼��������ܹ��ŵ�ֱ�ԣ����������ϸ������ѣ�����Ȱ��Ϸ��һ�����°ɡ����³�֮���ϸ��ض����������࿴!",me);
			say("�ݱ������������ھ�����ٶ��쳣���������Ͳ����ڻ������ӣ��㻯װ����ʦȥ��̽��̽���Ǳ�����ʲô�ڣ�",me);
			say("���¹�ϵ�ҳ����ӣ��������С�ģ�����й©���٣��ǵó��������һ㱨��",me);
			break;
		}
	}
	SendMenu(me);
	return 1;
}

int do_asw31(CChar * me)
{
	say("ֻ����˵�����Ŵ����������Ϊ��Ϊ��ʵ��������֮�䷶��������С�����Ŵ���Ϊ������",me);
	say("�Ŵ�����Ȼ��ʶ���£���ȴ����������ͷ��ʮ���ϸ���ʦ������",me);
	say("�ž�����ɫ����˵������������ˣ�����Ȱ��Ϸ��һ�����¡����³�֮���Ϸ�ض����á�����㣡",me);
	say("�ݱ������������ھ�����ٶ��쳣���������Ͳ����ڻ������ӣ��㻯װ����ʦȥ��̽��̽���Ǳ�����ʲô�ڣ�\n$COM���¹�ϵ�ҳ����ӣ��������С�ģ�����й©���٣��ǵó��������һ㱨����",me);
	say("���¹�ϵ�ҳ����ӣ��������С�ģ�����й©���٣��ǵó��������һ㱨����",me);
	me->set("zhang/����3",1);
	SendMenu(me);
	return 1;
}

int do_asw32(CChar * me)
{
	say("ֻ����˵�������Ŵ�������һ�����£��������ϡ�λ��Ȩ�أ������ޱȣ�����������ֱ�ӣ��������������������ž����أ���",me);
	say("�ž�����ɫ����˵������������ˣ�����Ȱ��Ϸ��һ�����¡����³�֮���Ϸ�ض����������мӣ�",me);
	say("�ݱ������������ھ�����ٶ��쳣���������Ͳ����ڻ������ӣ��㻯װ����ʦȥ��̽��̽���Ǳ�����ʲô�ڣ�",me);
	say("���¹�ϵ�ҳ����ӣ��������С�ģ�����й©���٣��ǵó��������һ㱨����",me);
	me->set("zhang/����3",2);
	SendMenu(me);
	return 1;
}

int do_asw33(CChar * me)
{
	say("�ž����������˵�������ƺ��п����԰����Ϸ�Ҳ�Ͳ���ǿ�ˡ�����Ȱ��Ϸ��һ�����°ɣ�",me);
	say("�ݱ������������ھ�����ٶ��쳣���������Ͳ����ڻ������ӣ��㻯װ����ʦȥ��̽��̽���Ǳ�����ʲô�ڣ�",me);
	say("���¹�ϵ�ҳ����ӣ��������С�ģ�����й©���٣��ǵó��������һ㱨����",me);
	me->set("zhang/����3",3);
	SendMenu(me);
	return 1;
}

int do_asw34(CChar * me)
{
	say("ֻ����˵����ˡ����ֱ�ԣ��Ŵ��˶Ե�������ƺ�̫�������ˣ������������۰���",me);
	say("�ž��г�˼����������ܹ��ŵ�ֱ�ԣ����������ϸ������ѣ�����Ȱ��Ϸ��һ�����°ɡ����³�֮���ϸ��ض����������࿴!",me);
	say("�ݱ������������ھ�����ٶ��쳣���������Ͳ����ڻ������ӣ��㻯װ����ʦȥ��̽��̽���Ǳ�����ʲô�ڣ�",me);
	say("���¹�ϵ�ҳ����ӣ��������С�ģ�����й©���٣��ǵó��������һ㱨����",me);
	me->set("zhang/����3",4);
	SendMenu(me);
	return 1;
}

int do_asw4(CChar * me)
{
	if(me->query("zhang/����")>=5 &&!me->query("zhang/����1"))
	{
		say( "��������ž���˵���������ˣ�Ŀǰ��û��ʲôüĿ��������¶�һ��ʱ��̽�顣��",me);
		say("�ž��е�ͷ�������ã����������������ϣ�����յô��ݱ�����",me);
		say("�ž��ж�������ζ�������50�㡣",me);
		me->add("zhang/����",50);
		me->set("zhang/����1",1);
	}
	else if(me->query("zhang/����")>=15 && !me->query("zhang/����2"))
	{
		say("��������ž���˵���������ˣ���΢��Щ�����ˣ�ԭ����Щ�ڶ��ǻʸ٣�������������ȥ�����������",me);
		say( "������¶�һ��ʱ��̽�飬���±ض��ܲ�����ġ���",me);
		say("�ž��г�˼����������ã��н�չ�ˡ���ɵò���ϣ�����������ס���",me);
		say("�ž��ж�������ζ�������100�㡣",me);
		me->add("zhang/����",100);
		me->set("zhang/����2",1);
	}
	else if(me->query("zhang/����")>=30)
	{
		say("��������ž���˵���������ˣ�ԭ�������ǻ�������׼����������ľ��ã���Ŀ����Ȼ��Ϊ�˴���������",me);
		say("�ž�����ɫ����˵����������������������ȥ�ɣ���ס����ǧ���ܸ����������𣡷���ɱ���⣡��",me);
		say("�ž��ж�������ζ�������150�㡣",me);
		say("������50000����Ǯ��������10000��Ĺٳ����顣",me);
		me->add("combat_exp",10000);
		CMoney::Pay_Player(me, 50000);
		me->add("zhang/����",150);
		me->del("zhang/����");
		me->del("zhang/����1");
		me->del("zhang/����2");
		me->set("zhang/����4",1);
		me->UpdateMe();
	}
	else
	{
		say("�ž�����ü��������ʲô��û��������������ʲô��",me);
	}
	SendMenu(me);
	return 1;
}

int do_asw5(CChar * me)
{
	if(!me->query_temp("zhang/��ʷë����"))
	{
		tell_object(me, "�ž������ŭɫ������������Ϣ����ʷë�������׼�������������������ң���������취�������졣��");
		me->set_temp("zhang/��ʷë����",1);
	}
	else
	{
		tell_object(me, "�ž����������죬�������ø�СС��ʷ����ķ������벻������ȥ���ʳɶ��İ������ɣ�û�õĶ�������");
		me->set_temp("zhang/������",1);
	}
	return 1;
}

int do_asw5_ok(CChar * me)
{
	int exp;
	char msg[255];
	time_t t;	
	time(&t);
	//Ԥ��ʱ���������̣���ɽ�����ͷ�����
	if(t<me->query("zhang/renwu5_endtime")-3000)
		t=me->query("zhang/renwu5_endtime")-3000;
	else if(t>me->query("zhang/renwu5_endtime")+3000)
		t=me->query("zhang/renwu5_endtime")+3000;
	//���������
	if(me->query("zhang/renwu5_ok"))
	{
		int repute;
		switch(me->query("zhang/renwu5_ok"))
		{
		case 1:
			exp=30000+10*(t-me->query("zhang/renwu5_endtime"));
			repute=30000+8*(t-me->query("zhang/renwu5_endtime"));
			break;
		case 2:
			exp=20000+8*(t-me->query("zhang/renwu5_endtime"));
			repute=20000+6*(t-me->query("zhang/renwu5_endtime"));
			break;
		case 3:
			exp=15000+6*(t-me->query("zhang/renwu5_endtime"));
			repute=15000+5*(t-me->query("zhang/renwu5_endtime"));
			break;
		case 4:
			exp=10000+5*(t-me->query("zhang/renwu5_endtime"));
			repute=10000+4*(t-me->query("zhang/renwu5_endtime"));
			break;
		}
		me->add("combat_exp", exp);
		me->add("repute",-repute);
		
		if(t > me->query("zhang/renwu5_endtime"))	
		{
			tell_object(me,"\n$HIY�ž��ж�ʱ������Ц������̾�������������ǲ�������,�������С�¾�ȻҲҪ����ô�á���\n�ž��ж�������ζ��½���100�㡣");
			me->receive_wound("hp", me->query("max_hp") / 3, this);
			me->receive_damage("hp", me->query("max_hp") / 2, this);
			me->add("zhang/����",-100);
			if(me->query("zhang/����")<0)
				me->del("zhang/����");
			me->SendState(me);
		}
		else
		{
			tell_object(me,"\n$HIG���׸�����Ц�������ã��ã��ã����°�Ĳ�����ȥ��Ϣ�ɣ�����\n�ž��ж�������ζ�������200�㡣");
			me->add("zhang/����",200);
		}
		
		tell_object(me, snprintf(msg, 255, "$HIC�������в����ʷë����������,�����%d�㾭�顢%d�㽭��������", exp,-repute));
		
		g_Channel.do_channel(&g_Channel, 0, "sys", 
			snprintf(msg, 255, "%s�����в����ʷë���������񣬻��%d���顢%d�㽭��������", me->name(1), exp,-repute));
		me->FlushMyInfo();
		
		me->set("zhang/����5",me->query("zhang/renwu5_ok"));
		me->del("zhang/renwu5");
		me->del("zhang/renwu5_ok");
		me->del("zhang/renwu5_endtime");
		me->delete_temp("zhang");
	}
	//����ʧ�ܳͷ�
	else
	{
		exp=30000+10*(t-me->query("zhang/renwu5_endtime"));
		if(me->query("combat_exp")<=exp)
			exp=me->query("combat_exp");
		exp=-exp;
		me->add("combat_exp", exp);
		me->reset_level();

		tell_object(me,"$HIY�ž��ж�ʱ������Ц������̾�������������ǲ�������,����\n�ž��ж�������ζ��½���200�㡣");
		tell_object(me, snprintf(msg, 255, "$HIC��в����ʷë����������ʧ��,�����½�%d�㾭�飡", exp));
		
		me->add("zhang/����",-200);
		if(me->query("zhang/����")<0)
			me->del("zhang/����");
		
		me->set("zhang/����5",99);
		me->del("zhang/renwu5");
		me->del("zhang/renwu5_ok");
		me->del("zhang/renwu5_endtime");
		me->delete_temp("zhang");
		me->receive_wound("hp", me->query("max_hp") / 3, this);
		me->receive_damage("hp", me->query("max_hp") / 2, this);
		me->SendState(me);
		me->FlushMyInfo();
	}
	return 1;
}

int do_asw6(CChar * me)
{
	if(!me->query_temp("zhang/����ָ��"))
	{
		tell_object(me, "�ž�����ɫ���أ����������������ܱ�������ָ�ӽ�פ���߾�֮���������ر�����ͨ��������˹��Ҵ󻼣����ٰ�ɱ֮����");
		me->set_temp("zhang/����ָ��",1);

		time_t t;	
		time(&t);
		double value =3600;//��ʱ60����
		t += (time_t)value;	
		if(!me->query("zhang/renwu6_endtime"))
			me->set("zhang/renwu6_endtime",t);
	}
	else
	{
		tell_object(me, "�ž�����������˵����������ӵ�������Ѿã��������޵�������ʿ�Ķ࣬����С��Ӧ������");
		tell_object(me, "�ž�����������ļ��������������������������߰���һ���ĸ�֮ʿ����������ˡ�������������Я��һ�������������");
		me->set_temp("zhang/����ǿ",1);
	}
	return 1;
}

int do_asw6_ok(CChar * me)
{
	int exp;
	char msg[255];
	time_t t;	
	time(&t);
	//Ԥ��ʱ���������̣���ɽ�����ͷ�����
	if(t<me->query("zhang/renwu6_endtime")-3200)
		t=me->query("zhang/renwu6_endtime")-3200;
	else if(t>me->query("zhang/renwu6_endtime")+3200)
		t=me->query("zhang/renwu6_endtime")+3200;

	if(me->query("zhang/renwu6_end")==1)
	{
		int repute;
		exp=30000+10*(t-me->query("zhang/renwu6_endtime"));
		repute=30000+8*(t-me->query("zhang/renwu6_endtime"));
		me->add("combat_exp", exp);
		me->add("repute",-repute);
		
		if(t > me->query("zhang/renwu6_endtime"))	
		{
			tell_object(me,"\n$HIY�ž��ж�ʱ������Ц������̾�������������ǲ�������,�������С�¾�ȻҲҪ����ô�á���\n�ž��ж�������ζ��½���150�㡣");
			me->receive_wound("hp", me->query("max_hp") / 3, this);
			me->receive_damage("hp", me->query("max_hp") / 2, this);
			me->add("zhang/����",-150);
			if(me->query("zhang/����")<0)
				me->del("zhang/����");
			me->SendState(me);
			me->set("zhang/����6",2);//�������ʱ
		}
		else
		{
			tell_object(me,"\n$HIG���׸�����Ц�������ã��ã��ã����°�Ĳ�����ȥ��Ϣ�ɣ�����\n�ž��ж�������ζ�������250�㡣");
			me->add("zhang/����",250);
			me->set("zhang/����6",1);//��ʱ�������
		}
		
		tell_object(me, snprintf(msg, 255, "$HIC������˴�ɱ����ָ�ӵ�����,�����%d�㾭�顢%d�㽭��������", exp,-repute));
		
		g_Channel.do_channel(&g_Channel, 0, "sys", 
			snprintf(msg, 255, "%s����˴�ɱ����ָ�ӵ����񣬻��%d���顢%d�㽭��������", me->name(1), exp,-repute));
		me->FlushMyInfo();

		me->del("zhang/renwu6_endtime");
		me->del("zhang/renwu6_end");
		me->delete_temp("zhang");
	}
	//����ʧ�ܳͷ�
	else if(me->query("zhang/renwu6_end")==2)
	{
		exp=30000+10*(t-me->query("zhang/renwu6_endtime"));
		if(me->query("combat_exp")<=exp)
			exp=me->query("combat_exp");
		exp=-exp;
		me->add("combat_exp", exp);
		me->reset_level();

		tell_object(me,"$HIY�ž��ж�ʱ������Ц������̾�������������ǲ�������,����\n�ž��ж�������ζ��½���300�㡣");
		tell_object(me, snprintf(msg, 255, "$HIC���ɱ����ָ�ӵ�����ʧ��,�����½�%d�㾭�飡", exp));
		
		me->add("zhang/����",-300);
		if(me->query("zhang/����")<0)
			me->del("zhang/����");
		
		me->set("zhang/����6",3);//����ʧ��
		me->del("zhang/renwu6_endtime");
		me->del("zhang/renwu6_end");
		me->delete_temp("zhang");

		me->receive_wound("hp", me->query("max_hp") / 3, this);
		me->receive_damage("hp", me->query("max_hp") / 2, this);
		me->SendState(me);
		me->FlushMyInfo();
	}
	else
	{
		tell_object(me,"$HIY����ֵ����㣬�������ף�������ô������һ���ģ���");
		me->receive_wound("hp", me->query("max_hp") / 3, this);
		me->receive_damage("hp", me->query("max_hp") / 2, this);
		me->SendState(me);
		me->FlushMyInfo();
	}
	return 1;
}

int do_asw7(CChar * me)
{
	tell_object(me, "\n$HIC�ž������治�죬������ͨ��֪�ز�ʶ̧�٣����º��������գ������������洫���ǿ鱦���ף�����Ȼ����˵�Ѿ�ʧ�ԡ���");
	tell_object(me, "$HIC����ȥ������£����в�������۾�֮�ﵱ����ɱ����\n");
	me->set_temp("zhang/renwi7_1",1);
	return 1;
}

NPC_END;




