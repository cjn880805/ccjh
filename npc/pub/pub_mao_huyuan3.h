//pub_mao_huyuan3.h
//秦波 2002-11-20

NPC_BEGIN(CNpub_mao_huyuan3);

virtual void create()
{	
	set_name("护院", "hu yuan");
	set("title", "毛府");
	set("gender", "男性");
	set("icon", triggerman2);
	set("attitude", "friendly");
	
	set("no_kill",1);

	set("str", 30+random(3));
	set("int", 30+random(3));
	set("con", 30+random(3));
	set("dex", 30+random(3));
	
	set("max_hp",20000);
	set("eff_hp",20000);
	set("hp", 20000);
	set("max_mp", 8000);
	set("mp",  8000);
	set("mp_factor",30);
	set("combat_exp", 5000000);
	set("level",80);

	set_temp("apply/no_黯然消魂", 1);
	set("no_chan",1);
	set("bigboss",1);

	switch(random(15)+1)
	{
	case 1:
		set_skill("force", 180+random(150));
		set_skill("taiji_shengong", 180+random(150));
		set_skill("dodge", 180+random(150));
		set_skill("tiyunzong", 180+random(150));
		set_skill("unarmed", 180+random(150));
		set_skill("taiji_quan", 180+random(150));
		set_skill("parry", 180+random(150));
		set_skill("sword", 180+random(150));
		set_skill("taiji_jian", 180+random(150));
		set_skill("blade", 180+random(150));
		set_skill("taiji_dao", 180+random(150));
		set_skill("taoism", 180+random(150));
		set_skill("literate", 180+random(150));
		
		map_skill("force", "taiji_shengong");
		map_skill("dodge", "tiyunzong");
		map_skill("unarmed", "taiji_quan");
		map_skill("parry", "taiji_jian");
		map_skill("sword", "taiji_jian");
		map_skill("blade", "taiji_dao");
		break;
	case 2:
		set_skill("force", 180+random(150));
		set_skill("dodge", 180+random(150));
		set_skill("parry", 180+random(150));
		set_skill("cuff", 180+random(150));
		set_skill("strike", 180+random(150));
		set_skill("sword", 180+random(150));
		set_skill("staff", 180+random(150));
		set_skill("finger", 180+random(150));
		set_skill("kurong_changong", 180+random(150));
		set_skill("tiannan_step", 180+random(150));
		set_skill("jinyu_quan", 180+random(150));
		set_skill("wuluo_zhang", 180+random(150));
		set_skill("duanjia_sword", 180+random(150));
		set_skill("sun_finger", 180+random(150));
		set_skill("lm_shangyang", 180+random(150));	
		set_skill("literate", 180+random(150));
		
		map_skill("force", "kurong_changong");
		map_skill("dodge", "tiannan_step");
		map_skill("finger", "sun_finger");
		map_skill("cuff", "jinyu_quan");
		map_skill("strike", "wuluo_zhang");
		map_skill("parry", "sun_finger");
		map_skill("sword", "duanjia_sword");
		map_skill("staff", "duanjia_sword");
		
		prepare_skill("cuff", "jinyu_quan");
		prepare_skill("strike", "wuluo_zhang");
		break;
	case 3:
		set_skill("persuading", 180+random(150));
		set_skill("throwing", 180+random(150));
		set_skill("force", 180+random(150));
		set_skill("dodge", 180+random(150));
		set_skill("finger", 180+random(150));
		set_skill("parry", 180+random(150));
		set_skill("strike", 180+random(150));
		set_skill("sword", 180+random(150));
		set_skill("blade", 180+random(150));
		set_skill("literate", 180+random(150));
		set_skill("mahayana", 180+random(150));
		set_skill("buddhism", 180+random(150));
		set_skill("jinding_zhang", 180+random(150));
		set_skill("tiangang_zhi", 180+random(150));
		set_skill("huifeng_jian", 180+random(150));
		set_skill("yanxing_dao", 180+random(150));
		set_skill("zhutian_bu", 180+random(150));
		set_skill("linji_zhuang", 180+random(150));
		
		map_skill("force","linji_zhuang");
		map_skill("finger","tiangang_zhi");
		map_skill("dodge","zhutian_bu");
		map_skill("strike","jinding_zhang");
		map_skill("sword","huifeng_jian");
		map_skill("blade","yanxing_dao");
		map_skill("parry","huifeng_jian");
		break;
	case 4:
		set_skill("persuading", 180+random(150));
		set_skill("force", 180+random(150));
		set_skill("unarmed", 180+random(150));
		set_skill("dodge", 180+random(150));
		set_skill("parry", 180+random(150));
		set_skill("hand",180+random(150));
		set_skill("staff", 180+random(150));
		set_skill("hamagong", 180+random(150));
		set_skill("chanchu_bufa", 180+random(150));
		set_skill("shexing_diaoshou", 180+random(150));
		set_skill("lingshe_zhangfa", 180+random(150));
		set_skill("xunshou_shu",180+random(150));
		
		map_skill("force", "hamagong");
		map_skill("dodge", "chanchu_bufa");
		map_skill("unarmed", "shexing_diaoshou");
		map_skill("hand", "shexing_diaoshou");
		map_skill("parry", "lingshe_zhangfa");
		map_skill("staff", "lingshe_zhangfa");
		break;
	case 5:
		set_skill("force", 180+random(150));           
		set_skill("huntian_qigong", 180+random(150));    
		set_skill("unarmed", 180+random(150));           
		set_skill("xianglong_zhang", 180+random(150));   
		set_skill("dodge", 180+random(150));      	     
		set_skill("xiaoyaoyou", 180+random(150));      
		set_skill("parry", 180+random(150));           
		set_skill("staff", 180+random(150));            
		set_skill("dagou_bang", 180+random(150));        
		set_skill("begging", 180+random(150));           
		set_skill("xunshou_shu", 180+random(150));
		
		map_skill("force", "huntian_qigong");
		map_skill("unarmed", "xianglong_zhang");
		map_skill("dodge", "xiaoyaoyou");
		map_skill("parry", "xianglong_zhang");
		map_skill("staff", "dagou_bang");
		
		prepare_skill("unarmed", "xianglong_zhang");
		break;
	case 6:
		set_skill("force", 180+random(150));
		set_skill("yunv_xinfa", 180+random(150));	
		set_skill("seaforce", 180+random(150));		
		set_skill("sword", 180+random(150));
		set_skill("yunv_jian", 180+random(150));
		set_skill("smithsword",180+random(150));	
		set_skill("dodge", 180+random(150));
		set_skill("xianyun_bufa", 180+random(150));	
		set_skill("parry", 180+random(150));
		set_skill("unarmed", 180+random(150));
		set_skill("meinv_quan", 180+random(150));    
		set_skill("anranxiaohun_zhang", 180+random(150));
		set_skill("tianluo_diwang", 180+random(150));
		set_skill("literate", 180+random(150));
		
		map_skill("force", "seaforce");
		map_skill("sword", "smithsword");
		map_skill("dodge", "xianyun_bufa");
		map_skill("parry", "anranxiaohun_zhang");
		map_skill("unarmed", "anranxiaohun_zhang");
		break;
	case 7:
		set_skill("cuff", 180+random(150));
		set_skill("force", 180+random(150));
		set_skill("dodge", 180+random(150));
		set_skill("parry", 180+random(150));
		set_skill("sword", 180+random(150));
		set_skill("strike",180+random(150));
		set_skill("unarmed", 180+random(150));
		set_skill("zixia_shengong", 180+random(150));
		set_skill("poyu_quan", 180+random(150));
		set_skill("huashan_sword", 180+random(150));
		set_skill("hunyuan_zhang", 180+random(150));
		set_skill("lonely_sword", 180+random(150));
		set_skill("huashan_shenfa",180+random(150));
		set_skill("literate", 180+random(150));
		set_skill("zhengqijue", 180+random(150));
		
		map_skill("cuff", "poyu_quan");
		map_skill("force", "zixia_shengong");
		map_skill("dodge", "huashan_shenfa");
		map_skill("parry", "lonely_sword");
		map_skill("sword", "lonely_sword");
		map_skill("strike", "hunyuan_zhang");
		break;
	case 8:
		set_skill("force", 180+random(150));
		set_skill("unarmed", 180+random(150));
		set_skill("dodge", 180+random(150));
		set_skill("parry", 180+random(150));
		set_skill("hand",180+random(150));
		set_skill("strike", 180+random(150));
		set_skill("sword",180+random(150));
		
		set_skill("zhemei_shou",180+random(150));
		set_skill("liuyang_zhang",180+random(150));
		set_skill("tianyu_qijian",180+random(150));
		set_skill("yueying_wubu",180+random(150));
		set_skill("bahuang_gong", 180+random(150));
		
		map_skill("force", "bahuang_gong");
		map_skill("strike","liuyang_zhang");
		map_skill("dodge", "yueying_wubu");
		map_skill("unarmed", "liuyang_zhang");
		map_skill("strike","liuyang_zhang");
		map_skill("hand", "zhemei_shou");
		map_skill("parry", "liuyang_zhang");
		map_skill("sword","tianyu_qijian");
		
		prepare_skill("strike","liuyang_zhang");
		prepare_skill("hand","zhemei_shou");
		break;
	case 9:
		set_skill("force", 180+random(150));
		set_skill("dodge", 180+random(150));
		set_skill("parry", 180+random(150));
		set_skill("unarmed", 180+random(150));
		set_skill("jiuyang_shengong", 180+random(150));
		set_skill("lingfa", 180+random(150));
		set_skill("shenghuo_lingfa", 180+random(150));
		set_skill("qiankun_danuoyi", 180+random(150));
		set_skill("shenghuo_xinfa", 180+random(150));
		
		map_skill("parry", "qiankun_danuoyi");
		map_skill("force", "jiuyang_shengong");
		map_skill("dodge", "qiankun_danuoyi");
		map_skill("lingfa", "shenghuo_lingfa");
		break;
	case 10:
		set_skill("force", 180+random(150));
		set_skill("sword", 180+random(150));
		set_skill("dodge", 180+random(150));
		set_skill("parry", 180+random(150));
		set_skill("unarmed",180+random(150));
		set_skill("strike",180+random(150));
		set_skill("finger",180+random(150));
		set_skill("literate",180+random(150));
		set_skill("taoism",180+random(150));
		set_skill("xiantian_qigong", 180+random(150));
		set_skill("xiantian_gong", 180+random(150));
		set_skill("quanzhen_jianfa",180+random(150));  
		set_skill("quanzhen_jian",180+random(150));  
		set_skill("jinyan_gong", 180+random(150));   
		set_skill("haotian_zhang", 180+random(150));   
		set_skill("sun_finger",180+random(150)); 
		
		map_skill("force", "xiantian_qigong");
		map_skill("sword", "quanzhen_jianfa");
		map_skill("dodge", "jinyan_gong");
		map_skill("parry", "quanzhen_jianfa");
		map_skill("strike", "haotian_zhang");
		map_skill("finger","sun_finger");
		
		prepare_skill("finger","sun_finger");
		prepare_skill("strike","haotian_zhang");
		break;
	case 11:
		set_skill("buddhism", 180+random(150));
		set_skill("literate", 180+random(150));
		set_skill("blade", 180+random(150));
		set_skill("claw", 180+random(150));
		set_skill("club", 180+random(150));
		set_skill("cuff", 180+random(150));
		set_skill("dodge", 180+random(150));
		set_skill("finger", 180+random(150));
		set_skill("force", 180+random(150));
		set_skill("hand", 180+random(150));
		set_skill("parry", 180+random(150));
		set_skill("staff", 180+random(150));
		set_skill("strike", 180+random(150));
		set_skill("sword", 180+random(150));
		set_skill("whip", 180+random(150));
		
		set_skill("banruo_zhang", 180+random(150));
		set_skill("cibei_dao", 180+random(150));
		set_skill("damo_jian", 180+random(150));
		set_skill("fengyun_shou", 180+random(150));
		set_skill("fumo_jian", 180+random(150));
		set_skill("hunyuan_yiqi", 180+random(150));
		set_skill("jingang_quan", 180+random(150));
		set_skill("longzhua_gong", 180+random(150));
		set_skill("luohan_quan", 180+random(150));
		set_skill("nianhua_zhi", 180+random(150));
		set_skill("pudu_zhang", 180+random(150));
		set_skill("qianye_shou", 180+random(150));
		set_skill("sanhua_zhang", 180+random(150));
		set_skill("riyue_bian", 180+random(150));
		set_skill("shaolin_shenfa", 180+random(150));
		set_skill("weituo_gun", 180+random(150));
		set_skill("wuchang_zhang", 180+random(150));
		set_skill("xiuluo_dao", 180+random(150));
		set_skill("yingzhua_gong", 180+random(150));
		set_skill("yijinjing", 180+random(150));
		set_skill("yizhi_chan", 180+random(150));
		set_skill("zui_gun", 180+random(150));
		
		map_skill("blade", "cibei_dao");
		map_skill("claw", "longzhua_gong");
		map_skill("club", "wuchang_zhang");
		map_skill("cuff", "luohan_quan");
		map_skill("dodge", "shaolin_shenfa");
		map_skill("finger", "yizhi_chan");
		map_skill("force", "yijinjing");
		map_skill("hand", "fengyun_shou");
		map_skill("parry", "nianhua_zhi");
		map_skill("staff", "weituo_gun");
		map_skill("strike", "banruo_zhang");
		map_skill("sword", "fumo_jian");
		map_skill("whip", "riyue_bian");
		
		prepare_skill("finger", "yizhi_chan");
		prepare_skill("strike", "banruo_zhang");
		break;
	case 12:
		set_skill("force", 180+random(150));
		set_skill("dodge", 180+random(150));
		set_skill("unarmed", 180+random(150));
		set_skill("strike", 180+random(150));
		set_skill("parry", 180+random(150));
		set_skill("staff", 180+random(150));
		set_skill("sword", 180+random(150));
		set_skill("literate", 180+random(150));
		
		set_skill("shenlong_xinfa", 180+random(150));
		set_skill("yixingbu", 180+random(150));
		set_skill("shenlong_bashi", 180+random(150));
		set_skill("huagu_mianzhang", 180+random(150));
		set_skill("shedao_qigong", 180+random(150));
		
		map_skill("force", "shenlong_xinfa");
		map_skill("dodge", "yixingbu");
		map_skill("unarmed", "shenlong_bashi");
		map_skill("strike", "huagu_mianzhang");
		map_skill("parry", "shedao_qigong");
		map_skill("sword", "shedao_qigong");
		
		prepare_skill("strike", "huagu_mianzhang");
		prepare_skill("unarmed", "shenlong_bashi");
		break;
	case 13:
		set_skill("force", 180+random(150));            
		set_skill("claw", 180+random(150));              
		set_skill("hand", 180+random(150));            
		set_skill("finger", 180+random(150));          
		set_skill("unarmed", 180+random(150));         
		set_skill("strike", 180+random(150));          
		set_skill("leg",180+random(150));	           
		set_skill("dodge", 180+random(150));           
		set_skill("parry", 180+random(150));            
		set_skill("sword", 180+random(150));           
		
		set_skill("anying_fuxiang", 180+random(150));    
		set_skill("tanzhi_shentong", 180+random(150));   
		set_skill("xuanfeng_leg", 180+random(150));      
		set_skill("luoying_shenzhang", 180+random(150));     
		set_skill("bibo_shengong", 180+random(150));     
		set_skill("luoying_shenjian", 180+random(150));  
		set_skill("yuxiao_jianfa", 180+random(150));       
		set_skill("lanhua_shou", 180+random(150));       
		set_skill("qimen_wuxing",180+random(150));       
		set_skill("literate", 180+random(150));           
		
		map_skill("force"  , "bibo_shengong");
		map_skill("finger" , "tanzhi_shentong");
		map_skill("hand"   , "lanhua_shou");
		map_skill("unarmed", "luoying_shenzhang");
		map_skill("strike", "luoying_shenzhang");
		map_skill("leg", "xuanfeng_leg");
		map_skill("dodge"  , "anying_fuxiang");
		map_skill("parry"  , "tanzhi_shentong");
		map_skill("sword"  , "tanzhi_shentong");
		
		prepare_skill("finger", "tanzhi_shentong");
		prepare_skill("hand", "lanhua_shou");
		break;
	case 14:
		set_skill("force", 180+random(150));
		set_skill("beiming_shengong", 180+random(150));
		set_skill("dodge", 180+random(150));
		set_skill("lingboweibu", 180+random(150));
		set_skill("unarmed", 180+random(150));
		set_skill("liuyang_zhang", 180+random(150));
		set_skill("parry", 180+random(150));
		set_skill("blade", 180+random(150));
		set_skill("xiaoyao_dao", 180+random(150));
		set_skill("zhemei_shou", 180+random(150));
		set_skill("hand", 180+random(150));
		set_skill("literate", 180+random(150));
		
		map_skill("force", "beiming_shengong");
		map_skill("dodge", "lingboweibu");      
		map_skill("hand", "zhemei_shou");
		map_skill("unarmed", "liuyang_zhang");
		map_skill("parry", "xiaoyao_dao");
		map_skill("blade", "xiaoyao_dao");
		
		prepare_skill("hand","zhemei_shou");
		prepare_skill("unarmed","liuyang_zhang");
		break;
	case 15:
		set_skill("throwing", 180+random(150));
		set_skill("feixing_shu", 180+random(150));        
		set_skill("force", 180+random(150));
		set_skill("huagong_dafa", 180+random(150));
		set_skill("dodge", 180+random(150));
		set_skill("zhaixinggong", 180+random(150));
		set_skill("strike",180+random(150));
		set_skill("xingxiu_duzhang", 180+random(150));
		set_skill("parry", 180+random(150));
		set_skill("staff", 180+random(150));
		set_skill("tianshan_zhang", 180+random(150));
		set_skill("literate", 180+random(150));
		set_skill("sanyin_wugongzhao", 180+random(150));
		set_skill("claw", 180+random(150));
		set_skill("poison", 180+random(150));
		
		map_skill("force", "huagong_dafa");
		map_skill("dodge", "zhaixinggong");
		map_skill("strike", "xingxiu_duzhang");
		map_skill("parry", "feixing_shu");
		map_skill("staff", "tianshan_zhang");
		map_skill("unarmed", "xingxiu_duzhang");
		map_skill("claw", "sanyin_wugongzhao");
		
		prepare_skill("unarmed", "xingxiu_duzhang");
		prepare_skill("claw", "sanyin_wugongzhao");
		break;	
	}
	
	carry_object("cloth")->wear();
	carry_object("changjian")->wield();
	
	set("chat_chance", 100);

}

virtual void die()
{
	message_vision("护院死了。", this);
	destruct(this);
}

virtual char * chat_msg()
{
	if(!query_temp("fight/is_fighting"))
		destruct(this);

	return 0;
}


NPC_END;




