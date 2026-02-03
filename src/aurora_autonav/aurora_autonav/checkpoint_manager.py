# checkpoint_manager.py
from typing import Optional, Set, List

class CheckpointManager:
    """チェックポイントのIDペア管理"""
    
    def __init__(self, checkpoint_pairs: List[Set[int]] = None):
        """
        Args:
            checkpoint_pairs: チェックポイントのIDペアリスト
                             例: [{1,2}, {3,4}, {5,6}]
        """
        if checkpoint_pairs is None:
            # デフォルト値
            self.checkpoint_pairs = [
                {1, 2},
                {3, 4},
                {5, 6},
            ]
        else:
            self.checkpoint_pairs = checkpoint_pairs
        
        self.passed_checkpoints = set()
    
    def identify_checkpoint(self, detected_ids: List[int]) -> Optional[int]:
        """
        検出されたマーカーIDからチェックポイント番号を判定
        
        Args:
            detected_ids: 検出されたマーカーIDのリスト
        
        Returns:
            チェックポイント番号（1始まり）、見つからなければNone
        """
        if len(detected_ids) < 2:
            return None
        
        detected_set = set(detected_ids)
        
        for idx, pair in enumerate(self.checkpoint_pairs):
            if pair.issubset(detected_set):
                cp_id = idx + 1
                if cp_id not in self.passed_checkpoints:
                    return cp_id
        
        return None
    
    def mark_as_passed(self, cp_id: int):
        """チェックポイントを通過済みとしてマーク"""
        self.passed_checkpoints.add(cp_id)
    
    def is_passed(self, cp_id: int) -> bool:
        """通過済みか確認"""
        return cp_id in self.passed_checkpoints
    
    def get_checkpoint_count(self) -> int:
        """通過したチェックポイント数を返す"""
        return len(self.passed_checkpoints)
    
    def reset(self):
        """リセット"""
        self.passed_checkpoints.clear()