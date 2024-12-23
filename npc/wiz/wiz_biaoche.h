//wiz_biaoche.h ��������
//�ز� 2002��2��12


NPC_BEGIN(CNwiz_biaoche);

void create()
{
	set_name("�ڳ�", "biao che");
	set("title", "�����ھ�");
	set("gender", "����");
	set("icon", tiger);
    set("long","һƥ�������ŵ�һ��С������������˽����鱦��");
	set("race", "Ұ��");
	set("age", 5);
	set("attitude","heroism");
	set("str", 1);
	set("dex", 1);
	set("con", 1);
	set("int", 1);
	set("repute", 10000);
	set("hp", 180000);
	set("max_hp", 180000);
	set("combat_exp", 1);
	set_weight(50000000);
	call_out(selfdest2,7200);
	set("no_huan",1);

};

void bl_move()
{
	char msg[255];
	CContainer * obj;
	obj=environment();

	CChar * player1;
	CChar * player2;
	CChar * player3;
	player1=(CChar * ) obj->present(querystr("keeper1"));
	player2=(CChar * ) obj->present(querystr("keeper2"));
	player3=(CChar * ) obj->present(querystr("keeper3"));
	set("eff_hp",query("max_hp"));

	static char baowu[121][20]={
		"baihongjian","bilinzhen","bishou","blade_1","blade_2","cleansword","dadao","zimuzhen",
		"dadao2","dafu","dagger","duanjian","fandog_sword","fenshuici","fork","fuchen","futou","green_sword",
		"green_water_sword","hammer","heilongbian",	"hothammer","huaji","hugesword","huoqiang","jinhua","jinlun",
		"jiujiebian","kandao","kuihuazhen","langyabang","leizhendang","longquansword","mandao","panguanbi",
		"putongbishou","qimeigun","qin","qingzugang","qingzuzang","qinqin_sword","ring_whip","ruanjian","sea_wood",
		"senggun","shebian","shenghuo_ling","shezhang","shield","shunvjian","shutonggun","snowsword","sword_1",
		"sword_2","sword_3","taomujian","tiepipa","tongren","walkingstick","wandao","wodao","wuqing_sword","xblade",
		"xem_sword","xiao","xiuhua","xuantiesword","xuedao","yangbian","yaochu","yaoqin","yinlun","youlongsword",
		"yufeng_zhen","yuxiao","yuzhu_zhang","zijinchui","zijin_staff",
		"38huoqiang","xuantiebishou","dagoubang","shenshe_staff","haoseshan","btzheng","taibaizao","zwsword",
		"lvzhuxiao","conglinjian","newyear","newyear1","century_war","tiancanbaojia","fannaomao","liaochengpao",
		"yinguozhu","bolanxie","zhangmenhuan","jinhuantoushi","ruanweijia","shajiezhi","zidiaopifeng","dulonglian",
		"yinmopao","diaojiandai","xiantianyu","poliquan","yanshuhua","fengyizhen","jinlianxie","kuihuaao","xuanwupao",
		"yunshenglv","zijianhun","qinjianhun","luoshenjin","linboxie","zueiyupao","hanyuzhi","lantiandai","cangzuihu",
		"rumengdai",
	};
	CContainer * bot;

	int i,j;
	int mp_b,hp_b;
	i=query("teapot/bl");

	if(player1->query("mp")<player1->query("max_mp")-800 && player1->query("hp")<player1->query("max_hp")-400)
	{
		if (random(i)>10 && player1->query("kill/guilt")==0)
		{
			mp_b=player1->query("max_mp")-player1->query("mp");
			if(mp_b>800)mp_b=800;
			mp_b=random(mp_b)+1;
			hp_b=player1->query("max_hp")-player1->query("hp");
			if(hp_b>400)hp_b=400;
			hp_b=random(hp_b)+1;
			message_vision(snprintf(msg, 255, "$HIR·�ߵ�һ�����￴��%s�������ꡢ���������ģ����һ�����ģ�̾�˿�����ת��Ӽ���ʢ��һ��˱��������ݵ��������ǰ��", player1->name(1)),this);
			message_vision(snprintf(msg, 255,"$HIR%sϲ�����⣬������л�����̻��ʵĺ�����ȥ��������������", player1->name(1)),this);
			message_vision(snprintf(msg, 255, "$HIR%s�������ָ���%d�㡢�����ָ���%d�㡣",player1->name(1),hp_b,mp_b), this);
			player1->add("mp",mp_b);
			player1->add("hp",hp_b);
		}
	}

	if(player2->query("mp")<player2->query("max_mp")-800 && player2->query("hp")<player2->query("max_hp")-400)
	{
		if (random(i)>10 && player2->query("kill/guilt")==0)
		{
			mp_b=player2->query("max_mp")-player2->query("mp");
			if(mp_b>800)mp_b=800;
			mp_b=random(mp_b)+1;
			hp_b=player2->query("max_hp")-player2->query("hp");
			if(hp_b>400)hp_b=400;
			hp_b=random(hp_b)+1;
			message_vision(snprintf(msg, 255, "$HIR·�ߵ�һ�����￴��%s�������ꡢ���������ģ����һ�����ģ�̾�˿�����ת��Ӽ���ʢ��һ��˱��������ݵ��������ǰ��", player2->name(1)),this);
			message_vision(snprintf(msg, 255,"$HIR%sϲ�����⣬������л�����̻��ʵĺ�����ȥ��������������", player2->name(1)),this);
			message_vision(snprintf(msg, 255, "$HIR%s�������ָ���%d�㡢�����ָ���%d�㡣",player2->name(1),hp_b,mp_b), this);
			player2->add("mp",mp_b);
			player2->add("hp",hp_b);
		}
	}

	if(player3->query("mp")<player3->query("max_mp")-800 && player3->query("hp")<player3->query("max_hp")-400)
	{
		if (random(i)>10 && player3->query("kill/guilt")==0)
		{
			mp_b=player3->query("max_mp")-player3->query("mp");
			if(mp_b>800)mp_b=800;
			mp_b=random(mp_b)+1;
			hp_b=player3->query("max_hp")-player3->query("hp");
			if(hp_b>400)hp_b=400;
			hp_b=random(hp_b)+1;
			message_vision(snprintf(msg, 255, "$HIR·�ߵ�һ�����￴��%s�������ꡢ���������ģ����һ�����ģ�̾�˿�����ת��Ӽ���ʢ��һ��˱��������ݵ��������ǰ��", player3->name(1)),this);
			message_vision(snprintf(msg, 255,"$HIR%sϲ�����⣬������л�����̻��ʵĺ�����ȥ��������������", player3->name(1)),this);
			message_vision(snprintf(msg, 255, "$HIR%s�������ָ���%d�㡢�����ָ���%d�㡣",player3->name(1),hp_b,mp_b), this);
			player3->add("mp",mp_b);
			player3->add("hp",hp_b);
		}
	}

	if (!random(15)&&random(i)>25 && player1->query("kill/guilt")==0&& player2->query("kill/guilt")==0&& player3->query("kill/guilt")==0)
	{
		hp_b=query("max_hp")-query("hp");
		if(hp_b>30000)hp_b=30000;
		hp_b=random(hp_b)+1;
		add("hp",hp_b);
		hp_b=hp_b*100/query("max_hp");
		message_vision(snprintf(msg, 255, "$HIR%s��%s��%s�����Ѿ����ò������ڳ�������������̾����", player1->name(1), player2->name(1), player3->name(1)),this);
		message_vision(snprintf(msg, 255,"$HIR%s�ۼ⣬��Ȼ���ֲ�Զ������һ�������̣�ϲ�����⣺�ֵ��ǣ������о��ˣ�ȥ������ڳ���һ�°ɣ�", player2->name(1)),this);
		message_vision(snprintf(msg, 255, "$HIR�ڳ���������ʦ���������;ö�������%ld�㡣",hp_b), this);
	}

	if (i==44 && player1->query("kill/guilt")==0 && player2->query("kill/guilt")==0 && player3->query("kill/guilt")==0)
	{
		if(player1->query("hp")<player1->query("max_hp"))player1->set("hp",player1->query("max_hp"));
		player1->set("eff_hp",player1->query("max_hp"));
		if(player1->query("mp")<player1->query("max_mp"))player1->set("mp",player1->query("max_mp"));
		if(player2->query("hp")<player2->query("max_hp"))player2->set("hp",player2->query("max_hp"));
		player2->set("eff_hp",player2->query("max_hp"));
		if(player2->query("mp")<player2->query("max_mp"))player2->set("mp",player1->query("max_mp"));
		if(player3->query("hp")<player3->query("max_hp"))player3->set("hp",player3->query("max_hp"));
		player3->set("eff_hp",player3->query("max_hp"));
		if(player3->query("mp")<player3->query("max_mp"))player3->set("mp",player1->query("max_mp"));

		message_vision(snprintf(msg, 255, "$HIR%s��%s��%sƣ�������ļ���Ѻ���ڳ�����ǰ��������ɫ����ʧȥ������ʱ���ǹɺ���׳־��", player1->name(1), player2->name(1), player3->name(1)),this);
		message_vision(snprintf(msg, 255,"$HIRǰ��ͻȻ��ð��һ������%s������������һ�����������г�����һ��ײ������������ϵ���������������ϣ��סһ�����ؼҡ�", player2->name(1)),this);
		message_vision(snprintf(msg, 255, "$HIRӭ������һ��ɽ����ģ������׳�����������ڳ���Ʈ�������С���죬����%s��%s��%s����һ��ȭ��˵����",player1->name(1), player2->name(1), player3->name(1)), this);
		message_vision("$HIR��ԭ����λ�Ǹ����ھ�����ү�ӵ����ѣ�ʧ���ˡ�ǰ�治Զ�������ֵܵĵ��̣���λ��������ȥ�ִ���Ϣһ�󣬺����ֵ�Ҳ����һ������ү����ǰ��һ�������顣��", this);
		message_vision(snprintf(msg, 255, "$HIR%s��%s���������������Ű��ɣ���������Χƣ���Ļ���ǣ��ֿ��˿����ڵ��µ�%s,���ɵ�Ӳ��ͷƤֻ�ø�����Ⱥ���ֺú�����ɽȥ��", player1->name(1), player3->name(1), player2->name(1)),this);
		message_vision(snprintf(msg, 255,"$HIRһҹ�޻����ڶ���%s��%s��%s��ȫ������ɽ֮�󣬲���ᵽ���ڳ��ϲ��СС��������ڽ����Ϻ��е������",player1->name(1), player2->name(1), player3->name(1)),this);
	}

	if (i==51)
	{
	    int lev=query("type");
		message_vision("ǰ��һλ�󸹱�����˴����ֺ���Ц������ӭ�˹�����ԭ��������ί�л��������ڵ����ˡ�",this);
		set("chat_chance",0l);
		if(EQUALSTR(querystr("keeper1"), player1->querystr("id")))
		{
			int exp = query("hp") / lev + 1;
			set("keeper1_exp", exp +random(exp/4));
			player1->add("combat_exp",query("keeper1_exp"));
			int repute=random(100)+100;
			if(player1->query("repute")<0)
				repute=-repute;
			player1->add("repute",repute);
			if(EQUALSTR(querystr("����"), player1->querystr("id")))
			{
				message_vision(snprintf(msg, 255, "%s�к��������ֽ��ڳ����˹�ȥ�����ֺ�����һ��Ҿ��˵�����Ҳ�������",player1->name(1)),this);
				int mey =query("hp")/lev*5 + 1;
				mey =mey+random(mey);
				CMoney::Pay_Player(player1, mey);
				if(query("lev")==4 && (player1->query("baobiao/count_ok")%10)==8)
				{
					message_vision(snprintf(msg, 255, "$HIR$NѺ�ڳɹ��������%d���顢%d�Ľ���������ͬʱ��������ֺ�%d������������������1�㡣$COM\n", query("keeper1_exp"),repute,mey), player1);
					player1->add("����",1);
				}
				else
					message_vision(snprintf(msg, 255, "$HIR$NѺ�ڳɹ��������%d���顢%d�Ľ���������ͬʱ��������ֺ�%d����$COM\n", query("keeper1_exp"),repute,mey), player1);
				g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%sѹ�ڳɹ������%ld���飡ͬʱ��������ֺ�%d����", player1->name(1), query("keeper1_exp"),mey));

			}
			else 
			{
				message_vision(snprintf(msg, 255, "$HIR$NѺ�ڳɹ��������%d���顢%d�Ľ�����������$COM\n", query("keeper1_exp"),repute), player1);
				g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%sѹ�ڳɹ������%ld���飡", player1->name(1), query("keeper1_exp")));
			}

			del("keeper1");
			del("keeper1_exp");
			player1->delete_temp("����");
			player1->add("baobiao/count_ok",1);
			if(player1->query("baobiao/count_ok")/100*100==player1->query("baobiao/count_ok"))
			{
				bot=load_item(baowu[random(121)]);
				bot->move(player1);
				g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, 
					"$HIR%s(%s)�������ڳɹ��ۼƴﵽ%d�Σ������ø����ھ����͵�һ�����$HIW%s$HIR��������$COM\n", 
					player1->name(1),player1->id(1),player1->query("baobiao/count_ok"),bot->name(1)));
				tell_object(player1, snprintf(msg, 255, 
					"���������ڳɹ��ۼƴﵽ%d�Σ������ø����ھ����͵�һ�����$HIW%s$HIR��������$COM\n", 
					player1->query("baobiao/count_ok"),bot->name(1)));
			}
			player1->add("baobiao/count_exp",query("keeper1_exp"));
			player1->set("baobiao/last_exp",query("keeper1_exp"));
			if(player1->query("zhang/����3"))
				player1->add("zhang/����",1);
			if(player1->query("zhang/����")==5||player1->query("zhang/����")==15||player1->query("zhang/����")==30)
			{
				tell_object(player1, "$HIC\n���ƺ�����ԼԼ�ľ������һЩʲô�������б�Ҫȥ�����׸��㱨һ�¡�\n");
			}
			if(player1->query("tradepro/index")==9)
			{
				tell_object(player1,snprintf(msg, 255,  "\n$HIW��ϲ�������%sί���������\n",player1->querystr("tradepro/quest_npc_name")));
				player1->set("tradepro/quest_ok",1);
			}
		}

		if(EQUALSTR(querystr("keeper2"), player2->querystr("id")))
		{
			int exp = query("hp") / lev + 1;
			set("keeper2_exp", exp +random(exp/4));
			player2->add("combat_exp", query("keeper2_exp"));
			int repute=random(100)+100;
			if(player2->query("repute")<0)
				repute=-repute;
			player2->add("repute",repute);
			if(EQUALSTR(querystr("����"), player2->querystr("id")))
			{
				message_vision(snprintf(msg, 255, "%s�к��������ֽ��ڳ����˹�ȥ�����ֺ�����һ��Ҿ��˵�����Ҳ�������",player2->name(1)),this);
				int mey =query("hp")/lev*5 + 1;
				mey =mey+random(mey);
				CMoney::Pay_Player(player2, mey);
				if(query("lev")==4 && (player2->query("baobiao/count_ok")%10)==8)
				{
					message_vision(snprintf(msg, 255, "$HIR$NѺ�ڳɹ��������%d���顢%d�Ľ���������ͬʱ��������ֺ�%d������������������1�㡣$COM\n", query("keeper2_exp"),repute,mey), player2);
					player2->add("����",1);
				}
				else
				message_vision(snprintf(msg, 255, "$HIR$NѺ�ڳɹ��������%d���顢%d�Ľ���������ͬʱ��������ֺ�%d����$COM\n", query("keeper2_exp"),repute,mey), player2);
				g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%sѹ�ڳɹ������%ld���飡ͬʱ��������ֺ�%d����", player2->name(1), query("keeper2_exp"),mey));

			}
			else 
			{
				message_vision(snprintf(msg, 255, "$HIR$NѺ�ڳɹ��������%d���顢%d�Ľ���������$COM\n", query("keeper2_exp"),repute), player2);
				g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%sѹ�ڳɹ������%ld���飡", player2->name(1), query("keeper2_exp")));
			}

			del("keeper2");
			del("keeper2_exp");
			player2->delete_temp("����");
			player2->add("baobiao/count_ok",1);
			if(player2->query("baobiao/count_ok")/100*100==player2->query("baobiao/count_ok"))
			{
				bot=load_item(baowu[random(121)]);
				bot->move(player2);
				g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, 
					"$HIR%s(%s)�������ڳɹ��ۼƴﵽ%d�Σ������ø����ھ����͵�һ�����$HIW%s$HIR��������$COM\n", 
					player2->name(1),player2->id(1),player2->query("baobiao/count_ok"),bot->name(1)));
				tell_object(player2, snprintf(msg, 255, 
					"���������ڳɹ��ۼƴﵽ%d�Σ������ø����ھ����͵�һ�����$HIW%s$HIR��������$COM\n", 
					player2->query("baobiao/count_ok"),bot->name(1)));
			}
			player2->add("baobiao/count_exp",query("keeper2_exp"));
			player2->set("baobiao/last_exp",query("keeper2_exp"));
			if(player2->query("zhang/����3"))
				player2->add("zhang/����",1);
			if(player2->query("zhang/����")==5||player2->query("zhang/����")==15||player2->query("zhang/����")==30)
			{
				tell_object(player2, "$HIC\n���ƺ�����ԼԼ�ľ������һЩʲô�������б�Ҫȥ�����׸��㱨һ�¡�\n");
			}
		}

		if(EQUALSTR(querystr("keeper3"), player3->querystr("id")))
		{
			int exp = query("hp") / lev + 1;
			set("keeper3_exp", exp + random(exp/4));
			player3->add("combat_exp", query("keeper3_exp"));
			int repute=random(100)+100;
			if(player3->query("repute")<0)
				repute=-repute;
			player3->add("repute",repute);
			if(EQUALSTR(querystr("����"), player3->querystr("id")))
			{
				message_vision(snprintf(msg, 255, "%s�к��������ֽ��ڳ����˹�ȥ�����ֺ�����һ��Ҿ��˵�����Ҳ�������",player3->name(1)),this);
				int mey =query("hp")/lev*5 + 1;
				mey =mey+random(mey);
				CMoney::Pay_Player(player3, mey);
				if(query("lev")==4 && (player3->query("baobiao/count_ok")%10)==8)
				{
					message_vision(snprintf(msg, 255, "$HIR$NѺ�ڳɹ��������%d���顢%d�Ľ���������ͬʱ��������ֺ�%d������������������1�㡣$COM\n", query("keeper3_exp"),repute,mey), player3);
					player3->add("����",1);
				}
				else
				message_vision(snprintf(msg, 255, "$HIR$NѺ�ڳɹ��������%d���顢%d�Ľ���������ͬʱ��������ֺ�%d����$COM\n", query("keeper3_exp"),repute,mey), player3);
				g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%sѹ�ڳɹ������%ld���飡ͬʱ��������ֺ�%d����", player3->name(1), query("keeper3_exp"),mey));

			}
			else 
			{
				message_vision(snprintf(msg, 255, "$HIR$NѺ�ڳɹ��������%d���顢%d�Ľ���������$COM\n", query("keeper3_exp"),repute), player3);
				g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%sѹ�ڳɹ������%ld���飡", player3->name(1), query("keeper3_exp")));
			}

			del("keeper3");
			del("keeper3_exp");
			player3->delete_temp("����");
			player3->add("baobiao/count_ok",1);
			if(player3->query("baobiao/count_ok")/100*100==player3->query("baobiao/count_ok"))
			{
				bot=load_item(baowu[random(121)]);
				bot->move(player3);
				g_Channel.do_channel(&g_Channel, 0, "news", snprintf(msg, 255, 
					"$HIR%s(%s)�������ڳɹ��ۼƴﵽ%d�Σ������ø����ھ����͵�һ�����$HIW%s$HIR��������$COM\n", 
					player3->name(1),player3->id(1),player1->query("baobiao/count_ok"),bot->name(1)));
				tell_object(player3, snprintf(msg, 255, 
					"���������ڳɹ��ۼƴﵽ%d�Σ������ø����ھ����͵�һ�����$HIW%s$HIR��������$COM\n", 
					player3->query("baobiao/count_ok"),bot->name(1)));
			}
			player3->add("baobiao/count_exp",query("keeper3_exp"));
			player3->set("baobiao/last_exp",query("keeper3_exp"));
			if(player3->query("zhang/����3"))
				player3->add("zhang/����",1);
			if(player3->query("zhang/����")==5||player3->query("zhang/����")==15||player3->query("zhang/����")==30)
			{
				tell_object(player3, "$HIC\n���ƺ�����ԼԼ�ľ������һЩʲô�������б�Ҫȥ�����׸��㱨һ�¡�\n");
			}
		}
		if(! querystr("keeper1")[0] && !querystr("keeper2")[0]&& !querystr("keeper3")[0])
			call_out(selfdest1, 3);

		return ;	// ����Ŀ�ĵأ�
	}

	if(!player1 || !player2 || !player3)
	{
	    message_vision("$HIR�����ֻ�ͷ�����������˼�λ���ڵ���ͷ�����ɵ���Щ���ң���ʱ��ͷ����������",this);
		message_vision("$HIR�����ֻ�ͷ�����������ڵ���ͷʼ�����˼�λ��������������һ�ţ���һ����Ĵ�ɢȥ��",this);
		remove_call_out(selfdest);
		call_out(selfdest,1);
		return ;
	}
	else
	{
		message_vision(snprintf(msg, 255, "%s�ȵ������ߣ����ߣ��ֵ��ǣ�����ǰͷ��ȥ��Ϣ��\n",player1->name(1)), this);
		message_vision("�����ֻ����ų��ޣ������ڳ���ǰ����ȥ��",this);
	
//		static char bnline1[51][20]={"������","������","��������","Ȫ��������","Ȫ������ƽԭ","Ȫ��ɽ·4","Ȫ��ɽ·5","Ȫ�ݱ���","Ȫ��","Ȫ�����ŵ���","��ɽ�ּ��14","��ɽ�ּ��13","��ɽ�ּ��11","��ɽ�ּ��10","��ɽ�ּ��9","��ɽ�ּ��8","��ɽ����","��ɽ����","��ɽ����","��ɽ�ּ��7","��ɽ�ּ��6","��ɽ�ּ��5","��ɽ�ּ��4","��ɽ�ּ��3","��ɽ�ּ��2","��ɽ�ּ��1","����ǻ���·","���������","�������","����Ǳ���","����ǲ軨ɽ1","����ǲ軨ɽ2","����ǲ軨ɽ5","����ǲ軨ɽ��","����Ǵ��ˮ�ٲ�","�������Ϫ��̶","����Ǳ̼�ɽ��","������س�С·2","����ǵ���ذ�1","�������٤��","�����ũ��2","�����ũ��3","�����ɽ·7","�����ɽ·8","�����������","���������","���������ɽ��","����ǰ�ɽ����","����ǲ��۲�","��������ƺ���","�������ϼɽ"};
//		static char bnline2[51][20]={"������","������","��������","Ȫ��������","Ȫ������ƽԭ","Ȫ��ɽ·4","Ȫ��ɽ·3","Ȫ��ɽ·2","Ȫ��ɽ·1","̩ɽ�����","̩ɽɽ��","�ƺӰ���5","������","�������ݳ�","���������9","���������8","���������4","���������3","���������2","���������1","��������","�����ʳ�","���������5","��ľ�»���·3","��ľ��ƽ����","��ľ�»���·2","��ľ����ʯ��","��ľ�»���·4","��ľ�����Ŷɿ�","�ƺ�2","�ƺ�3","�ƺ�����","�ƺ�ɳ��·","�ƺӹ���","�ƺӴ��","�ƺ�������","�ƺ�����","�ƺ�������","�ƺ�ʯϿ��","�ƺӱ�����","�ƺ�Ӫ��ˮ","�ƺӹų���","�ƺ�","�������ͱ�","������ɳ��","������ͭϿ","����С��","���ݻ���̲","������","���ݶ�","���ݴ󽫾���"};

		static char bnline1[51][20]={"������","�������д��","��ɽ����·","��ɽ����ɽ��","�䵱����·2","�䵱����·3","�䵱����","�䵱��ʯ���1","�䵱������","����С·","������ʯ��","����ǹٵ�1","����ǹٵ�2","����ǹٵ�3","�������گ�»���","�����̫�ͳ�","����Ǳ���","����Ƕ�ˮ��","������¹س�","����ǲ�ɽ�в�","����ǲ�ɽɽ·","����Ǻ���","����Ǻӱ�","�����ɽ��","����Ǹ�³��","���������","����ǰ͵ĵ�","����Ƕ���ˮ�ӹ�","����Ǳ���ѩɽ","�����ɽ·2","�����ɽ·4","�����ɽ·5","�����ɽ·6","����ǹŵ�","���������Ϫ�ذ�","�����˫����","���������","������ּ�С��2","����Ǻ�����","������ּ�С��1","�������Ϫ��̶","����Ǳ̼�ɽ��","������س�С·2","����ǵ���ذ�1","�������٤��","�����ũ��2","�����ũ��3","�����ɽ·7","�����ɽ·8","�����������","�����ɣ��"};
		static char bnline2[51][20]={"������","������","��������","Ȫ��������","Ȫ������ƽԭ","Ȫ��ɽ·4","Ȫ��ɽ·3","������ʯ���1","������ʯ���2","������ʯ���3","���ݺ鴺��","������ʯ���4","������ʯ���5","�����غ����1","�����غ����2","���ݴ�·1","�����غ����3","������ʯ���19","������ʯ���20","�����յ�7","�����յ�6","�����յ�5","�����յ�4","�����յ�3","�����յ�2","�����յ�1","������ʯ���6","������ʯ���7","������ʯ���8","������ʯ���9","������ʯ���10","������ʯ���11","������ʯ���12","������ʯ���13","������ʯ���14","������ʯ���15","�������ɽ��","����ɽ·7","�������ɽ��","����ɽ·6","�������ɽ","������ʯ���17","������ʯ���18","����ʯ�ݶ�","��������¤","����ˮ�ֶ�","������ϼ��","����ɽ·5","������·","����é�Ҳ�","���ݻ�����"};
		static char bnline3[51][20]={"������","������","��������","Ȫ��������","Ȫ������ƽԭ","Ȫ��ɽ·4","Ȫ��ɽ·3","Ȫ��ɽ·2","Ȫ��ɽ·1","̩ɽ�����","̩ɽɽ��","�ƺӰ���5","������","�������ݳ�","���������9","���������8","���������4","���������3","���������2","���������1","��������","�����ʳ�","���������5","��ľ�»���·3","��ľ��ƽ����","��ľ�»���·2","��ľ����ʯ��","��ľ�»���·4","��ľ�����Ŷɿ�","�ƺ�2","�ƺ�3","�ƺ�����","�ƺ�ɳ��·","�ƺӹ���","�ƺӴ��","�ƺ�������","�ƺ�����","�ƺ�������","�ƺ�ʯϿ��","�ƺӱ�����","�ƺ�Ӫ��ˮ","�ƺӹų���","�ƺ�","�������ͱ�","������ɳ��","������ͭϿ","����С��","���ݻ���̲","������","���ݶ�","���ݴ󽫾���"};
		static char bnline4[51][20]={"������","�������д��","��ɽ����·","��ɽ����ɽ��","��ɽ����","��ɽ����","��ɽ����","��ɽ�ּ��8","��ɽ�ּ��9","��ɽ�ּ��10","��ɽ�ּ��11","��ɽ�ּ��13","��ɽ�ּ��14","Ȫ�����ŵ���","Ȫ��","Ȫ�ݱ���","Ȫ��ɽ·5","Ȫ��ɽ·4","Ȫ������ƽԭ","Ȫ��ɽ·4","Ȫ��ɽ·3","������ʯ���1","������ʯ���2","������ʯ���3","���ݺ鴺��","������ʯ���4","������ʯ���5","�����غ����1","�����غ����2","���ݴ�·1","�����غ����3","������ʯ���19","������ʯ���20","�����յ�7","�����յ�6","�����յ�5","�����յ�4","�����յ�3","�����յ�2","�����յ�1","������ʯ���6","������ʯ���7","������ʯ���8","������ʯ���9","������ʯ���10","������ʯ���11","������ʯ���12","������ʯ���13","������ʯ���14","�����岨��","���ݾ۾�԰"};

		CRoom * troom;
		switch(query("teapot/idx"))
		{
		case 0:
			troom=load_room(bnline1[i]);
			break;
		case 1:
			troom=load_room(bnline2[i]);
			break;
		case 2:
			troom=load_room(bnline3[i]);
			break;
		case 3:
			troom=load_room(bnline4[i]);
			break;
		}
		if(atoi(querystr("������")))
			del("������");
		move(troom);
		player1->move(troom);
		player2->move(troom);
		player3->move(troom);

		if(player1->query_temp("biaoche/tangzishou")||player2->query_temp("biaoche/tangzishou")||player3->query_temp("biaoche/tangzishou"))
		{
			CNpc * tangzishou = load_npc("pub_tangzishou");
			tangzishou->set("owner",querystr("name"));
			tangzishou->move(troom);	
		}

		if (random(3000))
		{
			message_vision("�ࡪ���ۡ����������ס������ҡ����䡪��ά������",this);
		}
		else
		{
			message_vision("�ҡ����䡪��ά������,�ࡪ���ۡ����������ס���",this);
		}

		set("teapot/bl",i+1);
		//�������ڱ���ʱȷ��������ҹ���
		if(player1)
			player1->set_temp("����",1);
		if(player2)
			player2->set_temp("����",1);
		if(player3)
			player3->set_temp("����",1);
		switch(query("teapot/idx"))
		{
		case 0:	
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s��%s��%sִ�����������ߵ�%s�ˡ�",player1->name(1),player2->name(1),player3->name(1),bnline1[i]));
			break;
		case 1:
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s��%s��%sִ�����������ߵ�%s�ˡ�",player1->name(1),player2->name(1),player3->name(1),bnline2[i]));
			break;
		case 2:
			g_Channel.do_channel(&g_Channel, 0, "sys", snprintf(msg, 255, "%s��%s��%sִ�����������ߵ�%s�ˡ�",player1->name(1),player2->name(1),player3->name(1),bnline3[i]));
			break;
		}
		for(j=0;j<10000;j++)
		{
		}
		return ;
	}
}

char * chat_msg()
{
	char msg[255];

	CContainer * obj;
	obj=environment();

	CChar * player1;
	CChar * player2;
	CChar * player3;
	player1=(CChar * ) obj->present(querystr("keeper1"));
	player2=(CChar * ) obj->present(querystr("keeper2"));
	player3=(CChar * ) obj->present(querystr("keeper3"));
	set("eff_hp",query("max_hp"));

	if(!player1 || !player2 || !player3)
	{
		message_vision("$HIR�����ֻ�ͷ�����������˼�λ���ڵ���ͷ�����ɵ���Щ���ң���ʱ��ͷ����!",this);
		add("lost",1);
		if(query("lost")>50)
		{
			message_vision("$HIR�����ֻ�ͷ�����������ڵ���ͷʼ�����˼�λ��������������һ�ţ���һ����Ĵ�ɢȥ��",this);
			remove_call_out(selfdest);
			call_out(selfdest,3);
			return "";
		}
		return "";
	}

	if (!random(2))
	{
		if(random(4)==0)
		{
			message_vision("�����ֻ��������죬�����ȵ����ࡪ���ۡ����������ס���.", this);
			message_vision("������ӭ�ջ���һ����ޣ��������ҡ����䡪��ά������", this);
			if(!player1 || !player2 || !player3)
			{
				message_vision("$HIR�����ֻ�ͷ�����������˼�λ���ڵ���ͷ�����ɵ���Щ���ң���ʱ��ͷ������",this);
				add("lost",1);
				if(query("lost")>50)
				{
					message_vision("$HIR�����ֻ�ͷ�����������ڵ���ͷʼ�����˼�λ��������������һ�ţ���һ����Ĵ�ɢȥ��",this);
					remove_call_out(selfdest);
					call_out(selfdest,1);
					return "";
				}
				return "";
			}
			else
				bl_move();
		}
		else
		{
			if(!random(3))
			{
				if(!player1 || !player2 || !player3)
				{
					message_vision("$HIR�����ֻ�ͷ�����������˼�λ���ڵ���ͷ�����ɵ���Щ���ң���ʱ��ͷ������",this);
					add("lost",1);
					if(query("lost")>50)
					{
						message_vision("$HIR�����ֻ�ͷ�����������ڵ���ͷʼ�����˼�λ��������������һ�ţ���һ����Ĵ�ɢȥ��",this);
						remove_call_out(selfdest);
						call_out(selfdest,1);
						return "";
					}
					return "";
				}
				else
				{
					message_vision("ͻȻ�ܳ��˼�����Ӱ��Ϊ���ߴ�ȵ���",this);
					message_vision("$HIR��ɽ���ҿ���",this);
					message_vision("$HIR����������;",this);
					message_vision("$HIRҪ��Ӵ˹���",this);
					message_vision("$HIR������·�ƣ�",this);
					call_robber();
				}
			}
			else
				switch(random(5))
				{
					case 0:
						message_vision(snprintf(msg, 255, "%s�����������ֵ��ǣ�С���ˣ�������ǿ�����ڳ�û�ĵط�����Ҿ���㡣",player1->name(1)), this);
						break;
					case 1:
						message_vision(snprintf(msg, 255,"%s�����Աߵ�%s��%s˵�������������ô�ն���ǿ�˾�����û�ĵط�������λ�ֵܣ�ǧ��Ҫ��������ѽ,�ϻ��ҾͲ�����������ˡ�",player2->name(1),player1->name(1),player3->name(1)), this);
						break;
					case 2:
						message_vision(snprintf(msg, 255,"%s����������˵���ֵ��ǼӰ��Ͱ��������͵���ͷ��������̫��¥һ���ݡ�",player3->name(1)), this);
						break;
					case 3:
						message_vision(snprintf(msg, 255,"%s��%s˵�����������ڵĻ��Ƕཻ�����ٽ�ԩ�ҵĺã���������Ѫ�����Ӷ�������պ�������!",player1->name(1),player3->name(1)), this);
						break;
					case 4:
						message_vision("��~~~��~~~��~~~��~~����~~~~ͨ~~~~��~~��~~",this);
						break;
			}

		}
	}	
	else
	{
		switch(random(7))
		{
		case 0:
			message_vision(snprintf(msg, 255, "%s˵������������ȣ�ɹ��Ҫɱ���ˣ��ֵ��ǣ�������Ϣ�°ɣ�",player2->name(1)), this);
			break;
		case 1:
			message_vision(snprintf(msg, 255, "%s������Ĵյ�%s��ߣ�Ц����������˵������ôһ���������������ۺ죬�������Ǻϻ�����%s,��һ�����壬������Σ�",player3->name(1),player2->name(1),player1->name(1)), this);
			break;
		case 2:
			message_vision("�����ֻ��������죬�����ȵ����ࡪ���ۡ����������ס���", this);
			break;
		case 3:
			message_vision("������ӭ�ջ���һ����ޣ��������ҡ����䡪��ά������", this);
			break;
		case 4:
			message_vision(snprintf(msg, 255, "%s��Ȼ�����Աߵ���������Ӱһ�������ɵ�һ�󾪺����ֵ��Ǵ���㾫��ǰ�ߵĵ��κ��󲻶ԡ�",player2->name(1)),this);
			break;
		case 5:
			message_vision("�������ֹ����������������Ȱ�����һ��������÷���ͺ��ˡ�",this);
			break;
		case 6:
			if(!DIFFERSTR(player3->querystr("gender"), "����"))
				message_vision(snprintf(msg, 255, "%s��Ȼ̾���������������绹�����ܵȵ���׬�����Ǯ�ؼ�ȥȢ����",player3->name(1)),this);
			else
				message_vision(snprintf(msg, 255, "%s��Ȼ̾��������һ��û���ĵ��ˣ���ȻҪ�ҳ����������ֵ����ϵ�Ǯ��������С���š�",player3->name(1)),this);
			break;
		}
	}
	return "";
}

void call_robber()
{
	CChar * robber;
	CContainer * env = environment();

	CChar * player1;
	CChar * player2;
	CChar * player3;
	player1=(CChar * ) env->present(querystr("keeper1"));
	player2=(CChar * ) env->present(querystr("keeper2"));
	player3=(CChar * ) env->present(querystr("keeper3"));
	if(player2->query_temp("teapot/baobiao"))player2->delete_temp("teapot/baobiao");
	if(player3->query_temp("teapot/baobiao"))player3->delete_temp("teapot/baobiao");
	set("eff_hp",query("max_hp"));
	
	CFightRoom * obj;

	if(!player1 || !player2 || !player3)
	{
	   	message_vision("$HIR�����ֻ�ͷ�����������˼�λ���ڵ���ͷ�����ɵ���Щ���ң���ʱ��ͷ������",this);
		add("lost",1);
		if(query("lost")>30)
		{
			message_vision("$HIR�����ֻ�ͷ�����������ڵ���ͷʼ�����˼�λ��������������һ�ţ���һ����Ĵ�ɢȥ��",this);
			remove_call_out(selfdest);
			call_out(selfdest,3);
			return ;
		}
		return ;
	}
	else
	{
			obj = (CFightRoom *)load_item("fight_room");		
		
			obj->set("room_locked", FIGHT_LOCKED);
			obj->set_name( "����ս��", "fight_room_jiebiao");		
			obj->move(env);

			move(obj);
			obj->Join_Team(this, CFightRoom::FIGHT_TEAM_B);

			if(player1) 
			{
				player1->move(obj);
				obj->Join_Team(player1, CFightRoom::FIGHT_TEAM_B);
			}

			if(player2) 
			{
				player2->move(obj);
				obj->Join_Team(player2, CFightRoom::FIGHT_TEAM_B);
			}
			if(player3) 
			{
				player3->move(obj);
				obj->Join_Team(player3, CFightRoom::FIGHT_TEAM_B);
			}
			if(player1->query_temp("biaoche/tangzishou")||player2->query_temp("biaoche/tangzishou")||player3->query_temp("biaoche/tangzishou"))
			{
				CNpc * tangzishou = load_npc("pub_tangzishou");
				tangzishou->set("owner",querystr("name"));
				tangzishou->move(obj);
				obj->Join_Team(tangzishou, CFightRoom::FIGHT_TEAM_B);
			}
		static char qiangdao[15][20]={"pub_liujue","pub_gaoming","pub_zhongbuliang","pub_baiyulang","pub_weiziyi","pub_mowentian","pub_liufeiyan","pub_caodongyun","pub_duguo","pub_guoda","pub_liuquan","pub_maxiaotian","pub_wanghu","pub_wuan","pub_zhuzhao"};
		static char tufei[17][20]={"pub_duguo","pub_guoda","pub_liuquan","pub_maxiaotian","pub_wanghu","pub_wuan","pub_zhuzhao","pub_sangyuan","pub_wangmu","pub_henmantian","pub_guochou","pub_zhaoba","pub_feiying","pub_huanhai","pub_xuecai","pub_youzhu","pub_zangma"};
		static char xiaozei[9][20]={"pub_wangmu","pub_henmantian","pub_guochou","pub_zhaoba","pub_feiying","pub_huanhai","pub_xuecai","pub_youzhu","pub_zangma"};

		for(int i=0;i<random(3)+2;i++)
		{
			if(query("lev")==1)
				robber = load_npc(qiangdao[random(15)]);
			else if(query("lev")==2)
				robber = load_npc(tufei[random(17)]);
			else if(query("lev")==3)
				robber = load_npc(xiaozei[random(9)]);
			else
				robber = load_npc(qiangdao[random(15)]);
			//NPC��ò��־��з�������
			if(query("lev")==1 || query("lev")==4)
			{
				robber->set("bigboss",1);
				if(!random(5-query("lev")+1))
					robber->set("no_���־�",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_���־�",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_ǧ���׹�",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_��˼����",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_�ƺ�����",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_���־�",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_�������",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_ƴ��",1);
				if(!random(5-query("lev")+1))
					robber->set_temp("apply/no_��Ѫ��",1);
			}
			//����NPC�ķ�����������������HP��MP���ܾ��顢��������
			if(query("lev")==4)
			{
				robber->add_temp("apply/defense", 300/query("type"));
				robber->add_temp("apply/parry", 300/query("type"));
				robber->add_temp("apply/damage", 300/query("type"));
				robber->add("max_hp",robber->query("max_hp"));
				robber->add("hp",robber->query("hp"));
				robber->add("max_mp",robber->query("max_mp")/3);
				robber->add("mp",robber->query("mp")/3);
				robber->add("combat_exp",robber->query("combat_exp")/2);
				robber->add("str",robber->query("str")/2);
				robber->add("dex",robber->query("dex")/2);
				robber->add("con",robber->query("con")/2);
				robber->add("int",robber->query("int")/2);
			}
			char msg[255];
			robber->set("id",snprintf(msg, 255,"%s%d",robber->querystr("id"),random(1000)));
			robber->move(obj);
			obj->Join_Team(robber, CFightRoom::FIGHT_TEAM_A);				
		}
		obj->Begin_Fight(0);	
	}
}


static void selfdest(CContainer * ob, LONG param1, LONG param2)
{
	CNwiz_biaoche * npc = (CNwiz_biaoche *)ob;

	CContainer * me = ob->environment();

	CUser * player1;
	CUser * player2;
	CUser * player3;
	CUser * player4;
	player1=find_online(npc->querystr("keeper1"));
	player2=find_online(npc->querystr("keeper2"));
	player3=find_online(npc->querystr("keeper3"));
	if(atoi(npc->querystr("������")))
		player4=find_online(npc->querystr("������"));
	
	if(player1)
	{
		player1->delete_temp("����");
		player1->del("baobiao/count_ok");
	}
	if(player2)
	{
		player2->delete_temp("����");
		player2->del("baobiao/count_ok");
	}
	if(player3)
	{
		player3->delete_temp("����");
		player3->del("baobiao/count_ok");
	}
	if(atoi(npc->querystr("������")))
	{
		if(player4)
		{
			int repute=random(100)+100;
			int lev=npc->query("type");
			if(player4->query("repute")<0)
				repute=-repute;
			player4->add("repute",repute);
			int mey =npc->query("max_hp")/lev*2;
			mey=mey+random(10000);
			CMoney::Pay_Player(player4, mey);
			char msg[255];
			tell_object(player4, snprintf(msg, 255,"\n���ٳɹ����ػ�����%d��\n",mey));
			player4->command(snprintf(msg, 255, "chat 0 ����������ƾ����������è�Ĺ���Ҳ������죬��ү�ҽ�������ã��ͷ�����һ����·��%s���£������˿����", npc->name(1)));
		}
	}
	else
	{
		if(userp(me))
			tell_object((CChar *)me, "�ڳ�����һ�ţ������鱦ȫ��ɢ���ڵ��£����дܳ�һȺǿ����һӵ���ϣ���һ��������˾��⡣");
		else
			tell_room(me, "�ڳ�����һ�ţ������鱦ȫ��ɢ���ڵ��£����дܳ�һȺǿ����һӵ���ϣ���һ��������˾��⡣");
	}
	destruct(ob);
	return;
}


static void selfdest1(CContainer * ob, LONG param1, LONG param2)
{
	CContainer * me = ob->environment();

	if(userp(me))
		tell_object((CChar *)me, "$HIRһ�Ե�һȺ׳�����Ų�æ�Ľ�����ж�³������ŵ��Աߵ�һ�����ϣ�������ʻ��Զ����$COM");
	else
		tell_room(me, "$HIRһ�Ե�һȺ׳�����Ų�æ�Ľ�����ж�³������ŵ��Աߵ�һ�����ϣ�������ʻ��Զ����$COM");

	destruct(ob);
	return;
}

static void selfdest2(CContainer * ob, LONG param1, LONG param2)
{
	destruct(ob);
	return;
}

void die()
{
	selfdest(this, 0, 0);
}

virtual int accept_object(CChar * who, CContainer * ob)
{
	CContainer * obj;
	char msg[255];
	CChar * player2,*player3;

	if(who->is_busy())
		return notify_fail("����һ��������û�����");

	if(querystr("keeper3")[0])
		return notify_fail("�ࡪ���ۡ����������ס������ҡ����䡪��ά������");

	if(DIFFERSTR(ob->querystr("id"), "biaoqi") )
	{	
		say("û���ھֵ����죬��ô���߽�����", who);
		SendMenu(who);
		return 0;
	}

	if(DIFFERSTR(querystr("����"), ob->querystr("����")))
	{
		say("����ڳ��������ˣ�����������һ��ȥ��������", who);
		SendMenu(who);
		return 0;
	}
	
	if(DIFFERSTR(who->querystr("id"), querystr("����")))
	{
		if(EQUALSTR(querystr("ip/ip_address"),who->querystr_temp("client/ip_address")))
		{
			if(EQUALSTR(querystr("ip/ip_local"),who->querystr_temp("client/ip_local")))
			{
				say("�ҿ������죬������ô����Ҳ���ĳ�����ʵ˵���ǲ��Ǹղ����Ѿ����������ţ�", who);
				SendMenu(who);
				return 0;
			}
		}
		if(EQUALSTR(querystr("ip1/ip_address"),who->querystr_temp("client/ip_address")))
		{
			if(EQUALSTR(querystr("ip1/ip_local"),who->querystr_temp("client/ip_local")))
			{
				say("�ҿ������죬������ô����Ҳ���ĳ�����ʵ˵���ǲ��Ǹղ����Ѿ����������ţ�", who);
				SendMenu(who);
				return 0;
			}
		}
	}

	if(querystr("keeper1")[0] && querystr("keeper2")[0] && DIFFERSTR(querystr("keeper1"), who->querystr("id"))&& DIFFERSTR(querystr("keeper2"), who->querystr("id")))
	{
		say("��Ը�������ڣ��Ǽ����¡�", who);
	
		if(query("min_lev") > who->query("level"))
		{
			say("����������һ��������Ѫ�Ĺ��������ˮƽ��������", who);
			SendMenu(who);
			return 0;
		}
		if(query("max_lev") < who->query("level"))
		{			
			say("�����Դ����������֣��������ű����С�ڣ��ǲ����е�ʧ����ݡ�������", who);
			SendMenu(who);
			return 0;
		}
		set("keeper3", who->querystr("id"));
		int exp = query("hp") / 5 + 1;
		set("keeper3_exp", exp + random(exp/2));

		obj = environment();
		player2=(CChar * ) obj->present(querystr("keeper1"));
		player3=(CChar * ) obj->present(querystr("keeper2"));

		if(querystr("keeper1")[0] && !player2 && querystr("keeper2")[0] && !player3)
		{
			del("keeper1");
			del("keeper1_exp");
			del("keeper2");
			del("keeper2_exp");
			del("keeper3");
			del("keeper3_exp");
			say("�ף��ղ�˵Ҫ���ڵ���ȥ������ѽ����ȥ���ң������˿ɲ���ȫѽ��", who);
			SendMenu(who);
			return 0;
		}

//		player2->delete_temp("teapot/baobiao");
//		player3->delete_temp("teapot/baobiao");

		message_vision(snprintf(msg, 255,"$HIR�������ǽ�%s�������������ڳ��ϡ�",who->name(1)), this);
		message_vision("�����ֻ��������죬�����ȵ��������ˣ�",this);

		set("teapot/idx",random(4));
		set("chat_chance", 70);
		set_heart_beat(1);
		bl_move();
	}
	else if(querystr("keeper1")[0] && DIFFERSTR(querystr("keeper1"), who->querystr("id")))
	{
		say("��Ը�������ڣ��Ǽ����¡�", who);
	
		if(query("min_lev")>who->query("level"))
		{
			say("����������һ��������Ѫ�Ĺ��������ˮƽ��������", who);
			SendMenu(who);
			return 0;
		}
		if(query("max_lev")<who->query("level"))
		{			
			say("�����Դ����������֣��������ű����С�ڣ��ǲ����е�ʧ����ݡ�������", who);
			SendMenu(who);
			return 0;
		}
		if (who->query_temp("teapot/baobiao"))
		{
			say("��Ҫ�ż��ˣ����ſ�������û�б�����һ���ڡ�", who);
			SendMenu(who);
			return 0;
		}
		
		set("keeper2", who->querystr("id"));
		int exp = query("hp") / 5 + 1;
		set("keeper2_exp", exp + random(exp/2));
		say("ѹ������Σ�յ��£������˶��ã����ǵȵȰ�,���Ǵ��������������ߡ�", who);				 

		who->set_temp("teapot/baobiao",1);
		
		say("��Ҫ�ż��ˣ����ſ�������û�б�����һ���ڡ�", who);
		SendMenu(who);
		message_vision(snprintf(msg, 255,"$HIR�������ǽ�%s�������������ڳ��ϡ�",who->name(1)), this);
		set("ip1/ip_address",who->querystr_temp("client/ip_address"));
		set("ip1/ip_local",who->querystr_temp("client/ip_local"));
	}
	
	else
	{
		say("��Ը�������ڣ��Ǽ����¡�", who);
	
		if(query("min_lev")>who->query("level"))
		{
			say("����������һ��������Ѫ�Ĺ��������ˮƽ��������", who);
			SendMenu(who);
			return 0;
		}
		if(query("max_lev")<who->query("level"))
		{			
			say("�����Դ����������֣��������ű����С�ڣ��ǲ����е�ʧ����ݡ�������", who);
			SendMenu(who);
			return 0;
		}
		if (who->query_temp("teapot/baobiao"))
		{
			say("��Ҫ�ż��ˣ����ſ�������û�б�����һ���ڡ�", who);
			SendMenu(who);
			return 0;
		}

		set("keeper1", who->querystr("id"));
		int exp = query("hp") / 5 + 1;
		set("keeper1_exp", exp + random(exp/2));
		say("ѹ������Σ�յ��£������˶��ã����ǵȵȰ�,���Ǵ��������������ߡ�", who);

		who->set_temp("teapot/baobiao",1);

		say("��Ҫ�ż��ˣ����ſ�������û�б�����һ���ڡ�", who);
		SendMenu(who);
		message_vision(snprintf(msg, 255,"$HIR�������ǽ�%s�������������ڳ��ϡ�",who->name(1)), this);
	}
	return 1;
}

int handle_action(char *comm, CChar *me, char *arg)
{
	if(!strcmp(comm, "kill")  || !strcmp(comm, "fight") || !strcmp(comm, "cast") )
	{
		CContainer * env = environment();
		if(!me->query_temp("����"))
		{
			message_vision("$HIR$N����$n�Աߵ���λ���δ󺺻��ӵ�����ģ�����ֽŲ���һ��������ڵ���ͷ���ɵ�ɢȥ��", me, this);
			return 1;
		}
		else if(DIFFERSTR(env->querystr("base_name"),"fight_room"))
		{
			set("������",me->id(1));
			
			CChar * player1;
			CChar * player2;
			CChar * player3;
			player1=(CChar * ) env->present(querystr("keeper1"));
			player2=(CChar * ) env->present(querystr("keeper2"));
			player3=(CChar * ) env->present(querystr("keeper3"));
			CFightRoom * obj;
			
			if(!player1 || !player2 || !player3)
			{
				return CNpc::handle_action(comm, me, arg);
			}
			else
			{
				obj = (CFightRoom *)load_item("fight_room");		
				
				obj->set("room_locked", FIGHT_LOCKED);
				obj->set_name( "����ս��", "fight_room_jiebiao");		
				obj->move(env);
				
				me->move(obj);
				obj->Join_Team(me, CFightRoom::FIGHT_TEAM_A);

				move(obj);
				obj->Join_Team(this, CFightRoom::FIGHT_TEAM_B);
				
				if(player1) 
				{
					player1->move(obj);
					obj->Join_Team(player1, CFightRoom::FIGHT_TEAM_B);
				}
				
				if(player2) 
				{
					player2->move(obj);
					obj->Join_Team(player2, CFightRoom::FIGHT_TEAM_B);
				}
				if(player3) 
				{
					player3->move(obj);
					obj->Join_Team(player3, CFightRoom::FIGHT_TEAM_B);
				}
				if(player1->query_temp("biaoche/tangzishou")||player2->query_temp("biaoche/tangzishou")||player3->query_temp("biaoche/tangzishou"))
				{
					CNpc * tangzishou = load_npc("pub_tangzishou");
					tangzishou->set("owner",querystr("name"));
					tangzishou->move(obj);
					obj->Join_Team(tangzishou, CFightRoom::FIGHT_TEAM_B);
				}
				me->set_temp("pending/PK",1);
				obj->Begin_Fight(0);
				return 1;
			}
		}
	}
	return CNpc::handle_action(comm, me, arg);
}

NPC_END;




