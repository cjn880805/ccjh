// qi.h
//zhangdongni  2001-07-18

NPC_BEGIN(CNcity2_qi);
  virtual void create()
{
	set_name("袁世凯", "qi fangkai");
	set("long", "此人身材瘦长，却是气宇暄昂, 似乎身怀惊人艺业。\n");
	set("gender", "男性");
	set("age", 35);
	set("icon", young_man4);
	set("attitude", "peaceful");
	set("shen_type", -1);
	set("str", 30);
	set("int", 40);
	set("con", 30);
	set("dex", 30);
	
	set("max_hp", 1500);
	set("hp", 1500);
	set("mp", 500);
	set("max_mp", 500);
	set("mp_foctor", 50);
	set("combat_exp", 50000);
	set("score", 5000);

	set_skill("hunyuan_zhang", 70);
	set_skill("unarmed",80);
	set_skill("force", 80);
	set_skill("dodge", 80);
	set_skill("parry", 80);
	set_skill("sword", 80);

	map_skill("unarmed", "hunyuan_zhang");
	map_skill("parry", "hunyuan_zhang");

	set("env/wimpy", 60);
	set_inquiry("四十二章经", "咦，你也知道康亲王府里有宝书？");
	set_inquiry("书", "咦，你也知道康亲王府里有...？");
	set_inquiry("钥匙", "咦，你也知道取书要金钥匙？");
	
	set("chat_chance", 1);
	carry_object("cloth")->wear();
}
virtual char * chat_msg()				//NPC自动聊天
{
	switch(random(3))
	{
	case 0:
		return  "袁世凯忽然说: “今晚取了书我就走。”";
        case 1:
                return  "袁世凯一咬牙，说道:“这仆役太贪了，事成之后一定杀了他灭口。”";
	case 2:
	        return  "袁世凯自言自语道: “不行，只怕还有机关。”";
	}
	return 0;        
}
	
NPC_END;